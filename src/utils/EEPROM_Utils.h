#pragma once

#include "Arduboy2Ext.h"
#include "Enums.h"

class EEPROM_Utils {

  public: 

    EEPROM_Utils(){};
        
    static void initEEPROM(bool forceClear);
    static void EEPROM_Utils::getName(uint8_t *name, uint8_t startLoc);
    // static Slot getSlot(uint8_t x);
    // static uint8_t saveScore(uint16_t score);
    // static void writeChars(uint8_t slotIndex, HighScore &highScore);

};

