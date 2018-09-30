#include "GameOverState.h"
#include "../images/Images.h"


// ----------------------------------------------------------------------------
//  Initialise state ..
//
void GameOverState::activate(StateMachine & machine) {

	(void)machine;	

}


// ----------------------------------------------------------------------------
//  Handle state updates .. 
//
void GameOverState::update(StateMachine & machine) {

	auto & arduboy = machine.getContext().arduboy;
  auto justPressed = arduboy.justPressedButtons();
  auto pressed = arduboy.pressedButtons();

	// // Restart ?

	// if (pressed & DOWN_BUTTON) {

	// 	if (restart < UPLOAD_DELAY) {
	// 		restart++;
	// 	}
	// 	else {
	// 		arduboy.exitToBootloader();
	// 	}

	// }
	// else {
	// 	restart = 0;
	// }


	// // Handle other input ..

	// if (justPressed & A_BUTTON) {
	// 	machine.changeState(GameStateType::PlayerNames); 
	// }

}


// ----------------------------------------------------------------------------
//  Render the state .. 
//
void GameOverState::render(StateMachine & machine) {

	auto & ardBitmap = machine.getContext().ardBitmap;

	font4x6.setCursor(20, 28);
	font4x6.print("Game Over");

}
