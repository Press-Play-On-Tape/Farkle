#include "GameOverState.h"
#include "../images/Images.h"


// ----------------------------------------------------------------------------
//  Initialise state ..
//
void GameOverState::activate(StateMachine & machine) {
	
	this->winner = getWinner(machine);

}


// ----------------------------------------------------------------------------
//  Handle state updates .. 
//
void GameOverState::update(StateMachine & machine) {

	auto & arduboy = machine.getContext().arduboy;
  auto justPressed = arduboy.justPressedButtons();
  auto pressed = arduboy.pressedButtons();

	
	// Handle other input ..

	if (justPressed & A_BUTTON) {
		machine.changeState(GameStateType::TitleScreen); 
	}

}


// ----------------------------------------------------------------------------
//  Render the state .. 
//
void GameOverState::render(StateMachine & machine) {

	auto & ardBitmap = machine.getContext().ardBitmap;
	auto & arduboy = machine.getContext().arduboy;
	auto & gameStats = machine.getContext().gameStats;

	ardBitmap.drawCompressed(0, 45, Images::Title_Dice, WHITE, ALIGN_NONE, MIRROR_NONE);
	ardBitmap.drawCompressed(8, 0, Images::Winner, WHITE, ALIGN_NONE, MIRROR_NONE);

	ardBitmap.drawCompressed(32, 29, Images::Border_No_Shadow, WHITE, ALIGN_NONE, MIRROR_NONE);
	ardBitmap.drawCompressed(33, 30, Images::Icons[gameStats.players[this->winner].getIcon()], WHITE, ALIGN_NONE, MIRROR_NONE);

	font4x6.setCursor(49, 29);
	font4x6.print(gameStats.players[this->winner].name);
	arduboy.drawHorizontalDottedLine(54, 92, 38);
	font3x5.setCursor(54, 39);
  font3x5.print(F("Total"));
	BaseState::renderScore(machine, gameStats.players[this->winner].score, 78, 39);

}



uint8_t GameOverState::getWinner(StateMachine & machine) {

	auto & gameStats = machine.getContext().gameStats;

	uint8_t winnerIdx = 0;

	for (uint8_t i = 1; i < gameStats.numberOfPlayers; i++) {

		if (gameStats.players[i].score > gameStats.players[winnerIdx].score) {
			winnerIdx = i;
		}

	}

	return winnerIdx;

}
