#include "PlayGameState.h"
#include "../images/Images.h"


const uint8_t dicePositionX[] PROGMEM = { 0, 20, 40, 0, 20, 40, 0, 30 };
const uint8_t dicePositionY[] PROGMEM = { 0, 0, 0, 20, 20, 20, 42, 42 };


// ----------------------------------------------------------------------------
//  Initialise state ..
//
void PlayGameState::activate(StateMachine & machine) {

	auto & gameStats = machine.getContext().gameStats;

	this->viewState = ViewState::SwapPlayer;
	this->currentPlayer = gameStats.numberOfPlayers;
	this->round = 0;

}


// ----------------------------------------------------------------------------
//  Handle state updates .. 
//
void PlayGameState::update(StateMachine & machine) {

	auto & arduboy = machine.getContext().arduboy;
	auto & gameStats = machine.getContext().gameStats;
  auto justPressed = arduboy.justPressedButtons();

	switch (this->viewState) {

	 	case ViewState::SwapPlayer:

			this->currentPlayer++;
			this->currentRoll = 0;
			this->currentHand = 0;
			this->possibleHand = 0;
			this->viewState = ViewState::RollDice;

			if (this->currentPlayer >= gameStats.numberOfPlayers) {
				
				this->currentPlayer = 0;
				this->round++;
			
			}

			clearHand();

		case ViewState::RollDice:

			for (uint8_t i = 0; i < 6; i++) {

				if (this->dice[i] > 0) this->dice[i] = random(1, 7);

			} 

			this->possibleHand = calculateScore(true);	

			if (this->possibleHand > 0) {

				this->selectedDice = firstSelection();
				this->viewState = ViewState::SelectDice;

			}
			else {


				// Take 500 points from the player if they roll a Farkle ..

				int16_t score = gameStats.players[this->currentPlayer].score;
				gameStats.players[this->currentPlayer].score = score - FARKLE_PENALTY;
				this->viewState = ViewState::Farkle;

			}

			break;

		case ViewState::SelectDice:

			if (justPressed & LEFT_BUTTON) 	 	this->selectedDice = prevSelection(); 
			if (justPressed & RIGHT_BUTTON) 	this->selectedDice = nextSelection();

			if (justPressed & A_BUTTON) {
				
				switch (this->selectedDice) {
		
					case 0 ... 5:
						
						if (this->dice[this->selectedDice] > 0) {
							this->retainDice[this->selectedDice] = !this->retainDice[this->selectedDice];
						}

						this->currentRoll = calculateScore(false);	
						break;

					case 6: // Roll Again.

						for (uint8_t i = 0; i < 6; i++) {

							if (this->retainDice[i]) {
								this->dice[i] = 0;
							}

						} 

						// If all the dice have been played, roll them all again ..

						if (allDicePlayed()) clearHand();

						this->currentHand = this->currentHand + this->currentRoll;
						this->currentRoll = 0;
						this->viewState = ViewState::RollDice;					

						break;

					case 7:

						int16_t score = this->currentHand + this->currentRoll;
						gameStats.players[this->currentPlayer].score = gameStats.players[this->currentPlayer].score + score;

						viewState = ViewState::TakeScore;
						this->count = 0;
						break;

				}

			}

			break;

		case ViewState::TakeScore:
			
			if (this->count < (FLASH_FRAME_COUNT * 2)) {
				
				this->count++;

			}
			else {

				this->currentHand = 0;
				this->currentRoll = 0;

				if ((this->currentPlayer == gameStats.numberOfPlayers - 1) && (this->round == NUMBER_OF_ROUNDS_PER_GAME)) {

					machine.changeState(GameStateType::GameOver); 

				} 
				else {

					viewState = ViewState::SwapPlayer;

				}

			}

			break;

		case ViewState::Farkle:

			if (justPressed & A_BUTTON) {

				if ((this->currentPlayer == gameStats.numberOfPlayers - 1) && (this->round == NUMBER_OF_ROUNDS_PER_GAME)) {

					machine.changeState(GameStateType::GameOver); 

				} 
				else {

					viewState = ViewState::SwapPlayer;

				}

			}
			break;

	}

}


// ----------------------------------------------------------------------------
//  Render the state .. 
//
void PlayGameState::render(StateMachine & machine) {

	auto & arduboy = machine.getContext().arduboy;
	auto & gameStats = machine.getContext().gameStats;
	auto & ardBitmap = machine.getContext().ardBitmap;
	
	const bool flash = arduboy.getFrameCountHalf(FLASH_FRAME_COUNT);


	for (uint8_t i = 0; i < 8; i++) {

		uint8_t x = pgm_read_byte(&dicePositionX[i]);
		uint8_t y = pgm_read_byte(&dicePositionY[i]);

		switch (i) {

			case 0 ... 5:

				if (this->dice[i] > 0) {

					if (this->retainDice[i]) {
				
						ardBitmap.drawCompressed(x, y, Images::Dice_Solid, WHITE, ALIGN_NONE, MIRROR_NONE);
						ardBitmap.drawCompressed(x + 4, y + 4, Images::Dice_Faces[this->dice[i] - 1], BLACK, ALIGN_NONE, MIRROR_NONE);

					}
					else {
				
						ardBitmap.drawCompressed(x, y, Images::Dice_Hollow, WHITE, ALIGN_NONE, MIRROR_NONE);
						ardBitmap.drawCompressed(x + 4, y + 4, Images::Dice_Faces[this->dice[i] -1 ], WHITE, ALIGN_NONE, MIRROR_NONE);

					}

					if (i == this->selectedDice && flash) {

						ardBitmap.drawCompressed(x, y, Images::Dice_Highlight, BLACK, ALIGN_NONE, MIRROR_NONE);

					}  

				}
				else {

						ardBitmap.drawCompressed(x, y, Images::Dice_None, WHITE, ALIGN_NONE, MIRROR_NONE);

				}

				break;

			case 6:

				if (this->currentRoll > 0) {

					ardBitmap.drawCompressed(x, y, Images::Roll, WHITE, ALIGN_NONE, MIRROR_NONE);

					if (i == this->selectedDice && flash) {

						ardBitmap.drawCompressed(x, y, Images::Button_Highlight, BLACK, ALIGN_NONE, MIRROR_NONE);

					}  

				}

				break;

			case 7:

				if (this->currentRoll + this->currentHand >= MINIMUM_HAND_SCORE) {

					ardBitmap.drawCompressed(x, y, Images::Take, WHITE, ALIGN_NONE, MIRROR_NONE);

					if (i == this->selectedDice && flash) {

						ardBitmap.drawCompressed(x, y, Images::Button_Highlight, BLACK, ALIGN_NONE, MIRROR_NONE);

					}  

				}

				break;

		}

	}


	// Render player statistics ..

	ardBitmap.drawCompressed(67, 0, Images::Border_With_Shadow, WHITE, ALIGN_NONE, MIRROR_NONE);
	ardBitmap.drawCompressed(68, 1, Images::Icons[gameStats.players[this->currentPlayer].getIcon()], WHITE, ALIGN_NONE, MIRROR_NONE);

	font4x6.setCursor(84, -1);
	font4x6.print(gameStats.players[this->currentPlayer].name);

	arduboy.drawHorizontalDottedLine(89, 128, 8);

	font3x5.setCursor(89, 10);
	font3x5.print(F("Roll"));
	renderScore(machine, this->currentRoll, 113, 10);				
					
	font3x5.setCursor(89, 17);
	font3x5.print(F("Turn"));
	renderScore(machine, this->currentHand, 113, 17);				

	if (this->viewState != ViewState::TakeScore || flash) {

		font3x5.setCursor(89, 24);
		font3x5.print(F("Total"));
		renderScore(machine, gameStats.players[this->currentPlayer].score, 113, 24);

	}


	// Render round ..

	font3x5.setCursor(8, 58);
	font3x5.print(F("Turn~"));
	font3x5.print(this->round);
	font3x5.print(F("~of~"));
	font3x5.print(NUMBER_OF_ROUNDS_PER_GAME);


	// Render other players ..

	{
		uint8_t x = 67;

		for (uint8_t i = 0; i < 4; i++) {
		
			if (i != this->currentPlayer) {

				ardBitmap.drawCompressed(x, 37, Images::Border_With_Shadow, WHITE, ALIGN_NONE, MIRROR_NONE);
				ardBitmap.drawCompressed(x + 1, 38, Images::Icons[gameStats.players[i].getIcon()], WHITE, ALIGN_NONE, MIRROR_NONE);
				renderScore(machine, gameStats.players[i].score, x + 2, 58);
				x = x + 21;

			}

		}

	}


	// Farkle?

	if (this->viewState == ViewState::Farkle) {

		ardBitmap.drawCompressed(12, 8, Images::Farkle_Mask, BLACK, ALIGN_NONE, MIRROR_NONE);
		ardBitmap.drawCompressed(12, 8, Images::Farkle, WHITE, ALIGN_NONE, MIRROR_NONE);

	}

}


void PlayGameState::removeElement(byte* array, uint8_t elementNo, uint8_t arrayLength) {

	for (uint8_t x = elementNo; x < arrayLength - 1; x++) {
	
		array[x] = array[x + 1];

	}
	
	array[arrayLength - 1] = 0;

}


void PlayGameState::isort(uint8_t *a, uint8_t n) {

	for (uint8_t i = 1; i < n; ++i) {
		
		uint8_t j = a[i];
		int8_t k;

		for (k = i - 1; (k >= 0) && (j < a[k]); k--) {
			a[k + 1] = a[k];
		}

		a[k + 1] = j;

	}

}


uint16_t PlayGameState::calculateScore(boolean checkForFarkle) {
		
	uint8_t dice[6] = {0};
	uint8_t diceCount = 0;
	uint16_t score = 0;
		
	if (checkForFarkle) {
		
		for (uint8_t i = 0; i < 6; i++) {

			if (this->dice[i] > 0) {

					dice[diceCount] = this->dice[i];
					diceCount++;

			}

		}

	}
	else {

		for (uint8_t i = 0; i < 6; i++) {

			if (this->dice[i] > 0 && this->retainDice[i]) {

					dice[diceCount] = this->dice[i];
					diceCount++;

			}

		}

	}

	isort(dice, diceCount);
	
	if (diceCount > 0) {
			
		
		// Look for threes, fours, five, sixes ..
		
		for (uint8_t i = 1; i <= 6; i++) {
				
			int thisScore = 0;
			int counter = 0;
			
			for (uint8_t d = 0; d <  diceCount; d++) {
			
				if (dice[d] == i) {
				
					counter++;
				
				}
			
			}
			
			if (counter > 2) {
			
				switch (counter) {
				
					case 3:
					
						if (i == 1) { thisScore = thisScore + 1000; }
						if (i != 1) { thisScore = thisScore + (i * 100); }
						break;
					
					case 4:
					
						if (i == 1) { thisScore = thisScore + (1000 * 2); }
						if (i != 1) { thisScore = thisScore + (i * 100 * 2); }
						break;
					
					case 5:
					
						if (i == 1) { thisScore = thisScore + (1000 * 4); }
						if (i != 1) { thisScore = thisScore + (i * 100 * 4); }
						break;
					
					case 6:
					
						if (i == 1) { thisScore = thisScore + (1000 * 8); }
						if (i != 1) { thisScore = thisScore + (i * 100 * 8); }
						break;
				
				}
				
				
				// Remove items from collection if they have been added to score ..

				for (int8_t iRemove = diceCount; iRemove >= 0; iRemove--) {
				
					if (dice[iRemove] == i) {
					
						removeElement(dice, iRemove, 6);
						diceCount--;

					}
				
				}
				
				counter = 0;
				score = score + thisScore;
			
			}
				
		}
		
		
		// Look for hands of six (straights or three pairs) ..
		
		if (diceCount == 6) {
				
			if (dice[0] == 1 && dice[1] == 2 && dice[2] == 3 && dice[3] == 4 && dice[4] == 5 && dice[5] == 6) {
					
				score = score + 1500;
				diceCount=0;
				
			}
			else {
			
				if (dice[0] == dice[1] && dice[2] == dice[3] && dice[4] == dice[5]) {
					
					score = score + 750;
					diceCount=0;
					
				}
					
			}
				
		}
		
		
		// What about stray ones and fives?
		
		if (diceCount > 0) {
				
			for (int8_t iRemove = diceCount - 1; iRemove >= 0; iRemove--) {

				if (dice[iRemove] == 5) {

					removeElement(dice, iRemove, 6);
					diceCount--;
					score = score + 50;

				}
				else if (dice[iRemove] == 1) {
					
					removeElement(dice, iRemove, 6);
					diceCount--;
					score = score + 100;

				}
					
			}
				
		}
		
		
		// Any left overs ?

		if (!checkForFarkle && diceCount > 0) {

				score = 0;
				
		}
			
	}

	return score;

}


uint8_t PlayGameState::firstSelection() {

	for (int8_t i = 0; i < 6; i++) {

		if (this->currentRoll > 0) return i;

	}

	return 0;

}

uint8_t PlayGameState::prevSelection() {

	for (int8_t i = this->selectedDice - 1; i >= 0; i--) {

		if (i == 6) {

			if (this->currentRoll > 0) return 6;

		}
		else  {

			if (this->dice[i] > 0) return i;

		}

	}

	return this->selectedDice;

}


uint8_t PlayGameState::nextSelection() {

	for (uint8_t i = this->selectedDice + 1; i < 8; i++) {

		if (i < 6) {

			if (this->dice[i] > 0) return i;

		}
		else {

				if (i == 6 && this->currentRoll > 0) return 6;
				if (i == 7 && this->currentRoll + this->currentHand > 0) return 7;

		}

	}

	return this->selectedDice;

}

bool PlayGameState::allDicePlayed() {

	for (uint8_t i = 0; i < 6; i++) {

		if (this->dice[i] > 0) return false;

	}

	return true;

}

void PlayGameState::clearHand() {

	for (uint8_t i = 0; i < 6; i++) {

		this->dice[i] = 1;
		this->retainDice[i] = false;

	} 

}

void PlayGameState::renderScore(StateMachine & machine, int16_t score, uint8_t x, uint8_t y) {

	auto & arduboy = machine.getContext().arduboy;

	uint8_t digits[4] = {};
	extractDigits(digits, static_cast<uint16_t>(absT(score)));

	if (score < 0) { arduboy.drawFastHLine(x - 3, y + 3, 2); }

	for (uint8_t j = 4, x2 = x; j > 0; --j, x2 += 4) {
		font3x5.setCursor(x2, y);
		font3x5.print(digits[j - 1]);
	}

}