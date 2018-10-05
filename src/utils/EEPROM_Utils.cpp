#include "EEPROM_Utils.h"
#include "Arduboy2Ext.h"
#include "Enums.h"

/* ----------------------------------------------------------------------------
 *   Is the EEPROM initialised?
 *
 *   Looks for the characters 'F' and 'A' in the first two bytes of the EEPROM
 *   memory range starting from byte EEPROM_STORAGE_SPACE_START.  If not found,
 *   it resets the settings ..
 */

const uint8_t letter1 = 'F'; 
const uint8_t letter2 = 'A'; 

void EEPROM_Utils::initEEPROM(bool forceClear) {

  byte c1 = EEPROM.read(EEPROM_START_C1);
  byte c2 = EEPROM.read(EEPROM_START_C2);

  if (forceClear || c1 != letter1 || c2 != letter2) { 

    EEPROM.update(EEPROM_START_C1, letter1);
    EEPROM.update(EEPROM_START_C2, letter2);

    for (uint8_t x = EEPROM_PLAYER1; x <= EEPROM_END; x++) {

      EEPROM.update(x, 0);

    }

    for (uint8_t x = EEPROM_PLAYER1 + 1; x < EEPROM_PLAYER2 - 1; x++) {

      EEPROM.update(x, 32);
      EEPROM.update(x + 10, 32);
      EEPROM.update(x + 20, 32);
      EEPROM.update(x + 30, 32);
      EEPROM.update(x + 40, 32);
      EEPROM.update(x + 50, 32);
      EEPROM.update(x + 60, 32);

    }

  }

}


/* -----------------------------------------------------------------------------
 *   Get name ..
 */
void EEPROM_Utils::getName(char *name, uint8_t startLoc) {

  uint8_t chars[NAME_LENGTH + 1];

  for (uint8_t x = 0; x < NAME_LENGTH; x++) {
    
    chars[x] = EEPROM.read(startLoc + x);

  }

  chars[NAME_LENGTH] = 0;

  memcpy(name, &chars, NAME_LENGTH + 1);

}


/* -----------------------------------------------------------------------------
 *   Get name ..
 */
uint16_t EEPROM_Utils::getHighScore(uint8_t startLoc) {

  uint16_t score = 0;
  EEPROM.get(startLoc, score);

  return score;

}


static uint8_t EEPROM_Utils::saveScore(char *name, uint16_t score) {

  uint16_t scores[3];
  uint8_t idx = 255;

  for (uint8_t i = 0; i < 3; i++) {

    scores[i] = getHighScore(EEPROM_HS_SCORE_1 + (i*2));

    if (score > scores[i]) {

      idx = i;
      break;

    }

  }

  // New High Score ..
  if (idx < 255) {

    for (uint8_t i = 2; i > idx; i--) {

      for (uint8_t j = 0; j < NAME_LENGTH + 1; j++) {

        uint8_t x = EEPROM.read(EEPROM_HS_NAME_1 + ((i - 1) * 10) + j);
        EEPROM.update(EEPROM_HS_NAME_1 + (i * 10) + j, x);

      }

      uint16_t score = 0;
      EEPROM.get(EEPROM_HS_SCORE_1 + ((i -1) * 2), score);
      EEPROM.put(EEPROM_HS_SCORE_1 + (i * 2), score);

    }

  }

  return idx;

}



// /* -----------------------------------------------------------------------------
//  *   Get slot details. 
//  */
// Slot EEPROM_Utils::getSlot(uint8_t x) {

//   Slot slot;


//   slot.setChar0(EEPROM.read(EEPROM_TOP_START + (EEPROM_ENTRY_SIZE * x)));
//   slot.setChar1(EEPROM.read(EEPROM_TOP_START + (EEPROM_ENTRY_SIZE * x) + 1));
//   slot.setChar2(EEPROM.read(EEPROM_TOP_START + (EEPROM_ENTRY_SIZE * x) + 2));

//   uint16_t score = 0;
//   EEPROM.get(EEPROM_TOP_START + (EEPROM_ENTRY_SIZE * x) + 3, score);
//   slot.setScore(score);


//     return slot;

// }


// /* -----------------------------------------------------------------------------
//  *   Save score and return index.  255 not good enough! 
//  */
// uint8_t EEPROM_Utils::saveScore(uint16_t score) {

//   uint8_t idx = DO_NOT_EDIT_SLOT;

//   for (uint8_t x = 0; x < MAX_NUMBER_OF_SCORES; x++) {

//     Slot slot = getSlot(x);

//     if (slot.getScore() < score) {

//       idx = x;
//       break;

//     }

//   }

//   if (idx < DO_NOT_EDIT_SLOT) {

//     for (uint8_t x = MAX_NUMBER_OF_SCORES - 1; x > idx; x--) {

//       Slot slot = getSlot(x - 1);

//       EEPROM.update(EEPROM_TOP_START + (EEPROM_ENTRY_SIZE * x), slot.getChar0());
//       EEPROM.update(EEPROM_TOP_START + (EEPROM_ENTRY_SIZE * x) + 1, slot.getChar1());
//       EEPROM.update(EEPROM_TOP_START + (EEPROM_ENTRY_SIZE * x) + 2, slot.getChar2());
//       EEPROM.put(EEPROM_TOP_START + (EEPROM_ENTRY_SIZE * x) + 3, slot.getScore());

//     }

//     EEPROM.update(EEPROM_TOP_START + (EEPROM_ENTRY_SIZE * idx), 0);
//     EEPROM.update(EEPROM_TOP_START + (EEPROM_ENTRY_SIZE * idx) + 1, 0);
//     EEPROM.update(EEPROM_TOP_START + (EEPROM_ENTRY_SIZE * idx) + 2, 0);
//     EEPROM.put(EEPROM_TOP_START + (EEPROM_ENTRY_SIZE * idx) + 3, score);

//   }

//   return idx;

// }


// /* -----------------------------------------------------------------------------
//  *   Save characters in the nominated slot index. 
//  */
// void EEPROM_Utils::writeChars(uint8_t slotIndex, HighScore &highScore) {

//     EEPROM.update(EEPROM_TOP_START + (EEPROM_ENTRY_SIZE * slotIndex), highScore.getChar(0));
//     EEPROM.update(EEPROM_TOP_START + (EEPROM_ENTRY_SIZE * slotIndex) + 1, highScore.getChar(1));
//     EEPROM.update(EEPROM_TOP_START + (EEPROM_ENTRY_SIZE * slotIndex) + 2, highScore.getChar(2));

// }
