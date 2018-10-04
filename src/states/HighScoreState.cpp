#include "HighScoreState.h"
#include "../images/Images.h"


// ----------------------------------------------------------------------------
//  Initialise state ..
//
void HighScoreState::activate(StateMachine & machine) {
	
	auto & arduboy = machine.getContext().arduboy;

	arduboy.setRGBled(0, 0, 0);

	this->yLeft = -96;
	this->yRight = 0;

}


// ----------------------------------------------------------------------------
//  Handle state updates .. 
//
void HighScoreState::update(StateMachine & machine) {

	auto & arduboy = machine.getContext().arduboy;
  auto justPressed = arduboy.justPressedButtons();


	// Adjust the dice positions ..

	if (arduboy.everyXFrames(3)) {

		this->yLeft++;
		if (this->yLeft == 0) yLeft = -96;

		this->yRight--;
		if (this->yRight == -96) yRight = 0;

	}


	// Handle other input ..

	if (justPressed & A_BUTTON) {
		machine.changeState(GameStateType::TitleScreen); 
	}

}


// ----------------------------------------------------------------------------
//  Render the state .. 
//
void HighScoreState::render(StateMachine & machine) {

	auto & arduboy = machine.getContext().arduboy;
	auto & gameStats = machine.getContext().gameStats;

	SpritesB::drawOverwrite(27, 0, Images::HighScore, 0);

	SpritesB::drawOverwrite(-4, this->yLeft, Images::Title_Dice_Vert, 0);
	SpritesB::drawOverwrite(-4, this->yLeft + 96, Images::Title_Dice_Vert, 0);
	SpritesB::drawOverwrite(103, this->yRight, Images::Title_Dice_Vert_Mirror, 0);
	SpritesB::drawOverwrite(103, this->yRight + 96, Images::Title_Dice_Vert_Mirror, 0);

	font3x5.setHeight(7);
	font3x5.setCursor(37, 42);
	font3x5.print(F("ABCDABCD  0000\n"));
	font3x5.print(F("ABCDABCD  0000\n"));
	font3x5.print(F("ABCDABCD  0000\n"));
	font3x5.setHeight(8);

}

