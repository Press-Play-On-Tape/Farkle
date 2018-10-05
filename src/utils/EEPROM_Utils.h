#pragma once

#include "Arduboy2Ext.h"
#include "Enums.h"

class EEPROM_Utils {

  public: 

    EEPROM_Utils(){};
        
    static void initEEPROM(bool forceClear);
    static void getName(char *name, uint8_t startLoc);
    static uint16_t getHighScore(uint8_t startLoc);
    static uint8_t saveScore(char *name, uint16_t score);
    // static Slot getSlot(uint8_t x);
    // static uint8_t saveScore(uint16_t score);
    // static void writeChars(uint8_t slotIndex, HighScore &highScore);

};

