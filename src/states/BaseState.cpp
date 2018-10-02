#include "BaseState.h"

#include "../images/Images.h"
#include "../utils/Utils.h"
#include "../utils/Enums.h"
#include "../fonts/Font3x5.h"



void BaseState::renderScore(StateMachine & machine, int16_t score, uint8_t x, uint8_t y) {

	auto & arduboy = machine.getContext().arduboy;

	uint8_t digits[4] = {};
	extractDigits(digits, static_cast<uint16_t>(absT(score)));

	if (score < 0) { arduboy.drawFastHLine(x - 3, y + 3, 2); }

	for (uint8_t j = 4, x2 = x; j > 0; --j, x2 += 4) {
		font3x5.setCursor(x2, y);
		font3x5.print(digits[j - 1]);
	}

}