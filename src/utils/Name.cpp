#include "Name.h"
#include "Enums.h"

Name::Name() {
  
  _chars[0] = 0;
  
  for (uint8_t x = 1; x < NAME_LENGTH; x++) {
    _chars[x] = ' ';
  }

};
  


//--------------------------------------------------------------------------------------------------------------------------
// Properties ..

uint8_t Name::getCharIndex() {
  return _charIndex;
}

char Name::getChar(uint8_t idx) {
  return _chars[idx];
}

void Name::setCharIndex(uint8_t val) {
  _charIndex = val;
}

void Name::setChar(uint8_t idx, uint8_t val) {
  _chars[idx] = val;
}

void Name::setChars(char val[NAME_LENGTH]) {
  _charIndex = 0;
  memcpy(_chars, val, NAME_LENGTH);
}


//--------------------------------------------------------------------------------------------------------------------------
// Methods ..

void Name::incCharIndex() {
  if (_charIndex < NAME_LENGTH - 1) _charIndex++;
}

void Name::decCharIndex() {
  if (_charIndex > 0) _charIndex--;
}

uint8_t Name::getIcon() {
  return static_cast<uint8_t>(_chars[0]);
}

void Name::incChar(uint8_t idx) {
  
  if (idx == 0) {

    switch (_chars[idx]) {

      case ICON_MAX:
        _chars[idx] = 1;
        break;

      default:
        _chars[idx]++;
        break;

    }

  }
  else {

    switch (_chars[idx]) {

      case ASCII_SPACE:
        _chars[idx] = ASCII_CAPITAL_A;
        break;

      case ASCII_CAPITAL_A ... ASCII_CAPITAL_Y:
        _chars[idx]++;
        break;

      case ASCII_CAPITAL_Z:
        _chars[idx] = ASCII_LOWER_A;
        break;

      case ASCII_LOWER_A ... ASCII_LOWER_Y:
        _chars[idx]++;
        break;

      case ASCII_LOWER_Z:
        _chars[idx] = ASCII_SPACE;
        break;

      default:
        _chars[idx] = ASCII_CAPITAL_A;
        break;
        
    }

  }

}

void Name::decChar(uint8_t idx) {

  if (idx == 0) {

    switch (_chars[idx]) {

      case 1:
        _chars[idx] = ICON_MAX;
        break;

      default:
        _chars[idx]--;
        break;

    }

  }
  else {

    switch (_chars[idx]) {

      case ASCII_SPACE:
        _chars[idx] = ASCII_LOWER_Z;
        break;

      case ASCII_CAPITAL_A:
        _chars[idx] = ASCII_SPACE;
        break;

      case ASCII_CAPITAL_B ... ASCII_CAPITAL_Z:
        _chars[idx]--;
        break;

      case ASCII_LOWER_A:
        _chars[idx] = ASCII_CAPITAL_Z;
        break;

      case ASCII_LOWER_B ... ASCII_LOWER_Z:
        _chars[idx]--;
        break;

      default:
        _chars[idx] = ASCII_LOWER_Z;
        break;
      
    }

  }

}

void Name::clear() {

  _charIndex = 0;
  _chars[0] = 0;
      
  for (uint8_t x = 0; x < NAME_LENGTH; x++) {
    
    _chars[x] = ASCII_SPACE;

  }

}

void Name::clear(uint16_t startingLocation) {

  _charIndex = 0;
  _chars[0] = 0;
      
  for (uint8_t x = 0; x < NAME_LENGTH; x++) {
    
    _chars[x] = ASCII_SPACE;

  }

  Name::save(startingLocation);

}

void Name::retrieve(uint16_t startingLocation) {

  _charIndex = 0;
  _chars[0] = 0;
      
  for (uint8_t x = 0; x < NAME_LENGTH; x++) {
    
    _chars[x] = EEPROM.read(startingLocation + x);

  }

  // Has it been initialised ?  If not clear it ..

  if (_chars[1] != ASCII_SPACE    &&                     
     (_chars[1] < ASCII_CAPITAL_A || _chars[1] > ASCII_CAPITAL_Z) &&     
     (_chars[1] < ASCII_LOWER_A   || _chars[1] > ASCII_LOWER_Z)       
     ) { clear(startingLocation); }

}

void Name::save(uint16_t startingLocation) {

  for (uint8_t x = 0; x < NAME_LENGTH; x++) {
    
    EEPROM.update(startingLocation + x, getChar(x));

  }

}

char* Name::getString() {
  return _chars;
}
