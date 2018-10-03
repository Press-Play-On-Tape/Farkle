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

	if (arduboy.everyXFrames(2)) {

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

	SpritesB::drawOverwrite(-3, this->yLeft, Images::Title_Dice_Vert, 0);
	SpritesB::drawOverwrite(-3, this->yLeft + 96, Images::Title_Dice_Vert, 0);
	SpritesB::drawOverwrite(102, this->yRight, Images::Title_Dice_Vert_Mirror, 0);
	SpritesB::drawOverwrite(102, this->yRight + 96, Images::Title_Dice_Vert_Mirror, 0);

}

