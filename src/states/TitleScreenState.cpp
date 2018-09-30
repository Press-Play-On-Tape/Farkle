#include "TitleScreenState.h"
#include "../images/Images.h"

constexpr const static uint8_t UPLOAD_DELAY = 16;


// ----------------------------------------------------------------------------
//  Initialise state ..
//
void TitleScreenState::activate(StateMachine & machine) {

	(void)machine;	

}


// ----------------------------------------------------------------------------
//  Handle state updates .. 
//
void TitleScreenState::update(StateMachine & machine) {

	auto & arduboy = machine.getContext().arduboy;
  auto justPressed = arduboy.justPressedButtons();
  auto pressed = arduboy.pressedButtons();

	// Restart ?

	if (pressed & DOWN_BUTTON) {

		if (restart < UPLOAD_DELAY) {
			restart++;
		}
		else {
			arduboy.exitToBootloader();
		}

	}
	else {
		restart = 0;
	}


	// Handle other input ..

	if (justPressed & A_BUTTON) {
		machine.changeState(GameStateType::PlayerNames); 
	}

}


// ----------------------------------------------------------------------------
//  Render the state .. 
//
void TitleScreenState::render(StateMachine & machine) {

	auto & ardBitmap = machine.getContext().ardBitmap;
	
	ardBitmap.drawCompressed(12, 0, Images::Farkle, WHITE, ALIGN_NONE, MIRROR_NONE);
	ardBitmap.drawCompressed(0, 35, Images::Title_Dice, WHITE, ALIGN_NONE, MIRROR_NONE);

}
