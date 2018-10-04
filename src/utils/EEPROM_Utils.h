#pragma once

#include "Arduboy2Ext.h"
#include "Enums.h"

class EEPROM_Utils {

  public: 

    EEPROM_Utils(){};
        
    static void initEEPROM(bool forceClear);
    static Slot getSlot(uint8_t x);
    static uint8_t saveScore(uint16_t score);
    static void writeChars(uint8_t slotIndex, HighScore &highScore);

};


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

    uint16_t score = 10;

    EEPROM.update(EEPROM_START_C1, letter1);
    EEPROM.update(EEPROM_START_C2, letter2);

    for (uint8_t x = EEPROM_PLAYER1; x <= EEPROM_END; x++) {

      EEPROM.update(X, 0);

    }

  }

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
