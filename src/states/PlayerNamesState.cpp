#include "PlayerNamesState.h"
#include "../images/Images.h"


// ----------------------------------------------------------------------------
//  Initialise state ..
//
void PlayerNamesState::activate(StateMachine & machine) {

	auto & gameStats = machine.getContext().gameStats;

	this->viewState = ViewState::NumberOfPlayers;
	this->name.setChar(0, 1);

}


// ----------------------------------------------------------------------------
//  Handle state updates .. 
//
void PlayerNamesState::update(StateMachine & machine) {

	auto & arduboy = machine.getContext().arduboy;
	auto & gameStats = machine.getContext().gameStats;
  auto justPressed = arduboy.justPressedButtons();
  auto pressed = arduboy.pressedButtons();


	switch (this->viewState) {

		case ViewState::NumberOfPlayers:

			if (justPressed & B_BUTTON) 				{	machine.changeState(GameStateType::TitleScreen); }
			if (justPressed & A_BUTTON) 				{ viewState = ViewState::EnterName; }

			if ((justPressed & UP_BUTTON) || (justPressed & DOWN_BUTTON) || arduboy.isFrameCount(KEY_REPEAT_DELAY, this->frameCount)) {

					if ((pressed & UP_BUTTON) && gameStats.numberOfPlayers < 4) { 

						setNumberOfPlayers(machine, gameStats.numberOfPlayers + 1);
						this->frameCount = arduboy.getFrameCount(KEY_REPEAT_DELAY);

					}
					else if ((pressed & DOWN_BUTTON) && gameStats.numberOfPlayers > 1) { 

						setNumberOfPlayers(machine, gameStats.numberOfPlayers - 1);
						this->frameCount = arduboy.getFrameCount(KEY_REPEAT_DELAY);

					}

			}
			
			break;

		case ViewState::EnterName:
			{
				uint8_t charIndex = name.getCharIndex();

				if (justPressed & LEFT_BUTTON) 						 	{ name.decCharIndex(); } 
				if (justPressed & RIGHT_BUTTON) 					 	{ name.incCharIndex(); } 

				if ((justPressed & UP_BUTTON) || (justPressed & DOWN_BUTTON) || arduboy.isFrameCount(KEY_REPEAT_DELAY, frameCount)) {

					if (pressed & UP_BUTTON) { 

						name.incChar(charIndex); 
						frameCount = arduboy.getFrameCount(KEY_REPEAT_DELAY);

					}
					else if (pressed & DOWN_BUTTON) { 

						name.decChar(charIndex); 
						frameCount = arduboy.getFrameCount(KEY_REPEAT_DELAY);

					}
					
				}


				// Go back a player or to number of players screen ..

				if (justPressed & B_BUTTON) { 

					if (gameStats.playerBeingEdited > 1) {
					
						updatePlayerName(machine);
						gameStats.playerBeingEdited--;
						getPlayerName(machine);

					}
					else {

						viewState = ViewState::NumberOfPlayers;

					}

				}


				// Go forward to next player or start game ..

				if (justPressed & A_BUTTON) { 
	
					bool allSpaces = true;
					
					for (uint8_t x = 1; x < NAME_LENGTH; x++) {

						if (name.getChar(x) != ' ') allSpaces = false;

					}			

					if (!allSpaces) {

						updatePlayerName(machine);

Serial.print("yyy ");
Serial.print(gameStats.playerBeingEdited);
Serial.print(" ");
Serial.println(gameStats.numberOfPlayers);

						if (gameStats.playerBeingEdited < gameStats.numberOfPlayers)  {
							
								gameStats.playerBeingEdited++;
								getPlayerName(machine);
						
						}
						else {

							machine.changeState(GameStateType::PlayGame); 

						}

					}
					
				}

			}

			break;

	}

}


// ----------------------------------------------------------------------------
//  Render the state .. 
//
void PlayerNamesState::render(StateMachine & machine) {

	auto & arduboy = machine.getContext().arduboy;
	auto & ardBitmap = machine.getContext().ardBitmap;
	auto & gameStats = machine.getContext().gameStats;
	
	const bool flash = arduboy.getFrameCountHalf(FLASH_FRAME_COUNT);


	ardBitmap.drawCompressed(0, 35, Images::Title_Dice, WHITE, ALIGN_NONE, MIRROR_NONE);

	switch (this->viewState) {

		case ViewState::NumberOfPlayers:
			font4x6.setCursor(0, 8);
			font4x6.print(F("Number~of~players~? "));
			font4x6.print(gameStats.numberOfPlayers);

			if (flash) {
				arduboy.drawFastHLine(94, 16, 4);
			}

			break;

		case ViewState::EnterName:

			font4x6.setCursor(6, 0);
			font4x6.print(F("Player~"));
			font4x6.print(gameStats.playerBeingEdited);

			font4x6.setCursor(6, 9);
			font4x6.print(F("Icon?"));

			ardBitmap.drawCompressed(60, 1, Images::Border_No_Shadow, WHITE, ALIGN_NONE, MIRROR_NONE);
			ardBitmap.drawCompressed(61, 2, Images::Icons[static_cast<uint8_t>(name.getChar(0))], WHITE, ALIGN_NONE, MIRROR_NONE);

			if (flash && name.getCharIndex() == 0) {
				arduboy.drawFastHLine(62, 20, 15, WHITE);
			}

			font4x6.setCursor(6, 25);
			font4x6.print(F("Name?"));
			arduboy.drawHorizontalDottedLine(60, 94, 33);

			for (uint8_t x = 1; x < NAME_LENGTH; x++) {

				font4x6.setCursor(54 + (x * NAME_CHARACTER_SPACING), 25);

				if (flash && name.getCharIndex() == x) {
					arduboy.drawFastHLine(54 + (x * NAME_CHARACTER_SPACING), 33, 4, WHITE);
				}

				font4x6.print(name.getChar(x));

			}

			break;

	}

}

void PlayerNamesState::getPlayerName(StateMachine & machine) {
			
	auto & gameStats = machine.getContext().gameStats;

	this->name.setChars(gameStats.players[gameStats.playerBeingEdited - 1].name);
	this->name.clearIconsInUse();

	// if (gameStats.playerBeingEdited - 1 != 0) this->name.addIconsInUse(gameStats.players[0].getIcon());
	// if (gameStats.playerBeingEdited - 1 != 1) this->name.addIconsInUse(gameStats.players[1].getIcon());
	// if (gameStats.playerBeingEdited - 1 != 2) this->name.addIconsInUse(gameStats.players[2].getIcon());
	// if (gameStats.playerBeingEdited - 1 != 3) this->name.addIconsInUse(gameStats.players[3].getIcon());

}

void PlayerNamesState::updatePlayerName(StateMachine & machine) {
		
	auto & gameStats = machine.getContext().gameStats;
	strcpy(gameStats.players[gameStats.playerBeingEdited - 1].name, this->name.getString());

}

void PlayerNamesState::setNumberOfPlayers(StateMachine & machine, uint8_t numberOfPlayers) {
				
	auto & gameStats = machine.getContext().gameStats;

	if (gameStats.numberOfPlayers < numberOfPlayers) {
		
//		gameStats.players[numberOfPlayers - 1].setIcon(numberOfPlayers);

	}
	else {

//		gameStats.players[numberOfPlayers].setIcon(0);

	}

	gameStats.numberOfPlayers = numberOfPlayers;

}