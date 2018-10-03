#pragma once

#include <stdint.h>
#include "Utils.h"

#define _DEBUG
#define SOUND

#define NAME_LENGTH 9
#define NAME_CHARACTER_SPACING 6
#define NAME_UNDERLINE_WIDTH 3

#define ASCII_SPACE 32
#define ASCII_CAPITAL_A 65
#define ASCII_CAPITAL_B 66
#define ASCII_CAPITAL_Y 89
#define ASCII_CAPITAL_Z 90
#define ASCII_LOWER_A 97
#define ASCII_LOWER_B 98
#define ASCII_LOWER_Y 121
#define ASCII_LOWER_Z 122

#define KEY_REPEAT_DELAY 24
#define FLASH_FRAME_COUNT 20
#define FLASH_FRAME_COUNT_2 56
#define ICON_MAX 6
#define PLAYER_MAX 4
#define FARKLE_DELAY 14

#define FARKLE_PENALTY 500
#define MINIMUM_HAND_SCORE 300
#define NUMBER_OF_ROUNDS_PER_GAME 10//sjh

enum class GameStateType : uint8_t {
	SplashScreen,
	TitleScreen,
  PlayerNames,
  PlayGame,
  GameOver,
  HighScore
};

struct Player {

  public: 
   
    Player() {

      for (uint8_t x = 1; x < NAME_LENGTH; x++) {
        name[x] = ' ';
      }

    };

    uint8_t getIcon() {
      return static_cast<uint8_t>(this->name[0]);
    }

    void setIcon(uint8_t val) {
      this->name[0] = static_cast<char>(val);
    }

    char name[NAME_LENGTH + 1];
    int16_t score = 0;

};

struct GameStats {

  public: 
    
    GameStats() { };

    Player player1;
    Player player2;
    Player player3;
    Player player4;

    Player players[4] = { player1, player2, player3, player4 };
    
    uint8_t numberOfPlayers = 1;
    uint8_t playerBeingEdited = 1;

    void resetGame() {

      numberOfPlayers = 1;
      playerBeingEdited = 1;

      player1.setIcon(1);
      player2.setIcon(0);
      player3.setIcon(0);
      player4.setIcon(0);

    }

};