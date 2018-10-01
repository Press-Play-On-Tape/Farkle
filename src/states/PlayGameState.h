#pragma once

#include "../utils/GameContext.h"
#include "../utils/GameState.h"
#include "../utils/Enums.h"
#include "../utils/Name.h"
#include "../images/Images.h"
#include "BaseState.h"

class PlayGameState : public BaseState {

  private:

    enum class ViewState : uint8_t {
      SwapPlayer,
      RollDice,
      SelectDice,
      TakeScore,
      NextUp,
      Farkle
    };

    ViewState viewState = ViewState::RollDice;

    int8_t currentPlayer = -1;
    int8_t selectedDice = 0; 
    uint8_t dice[6];
    uint8_t round;
    uint8_t count;

    uint16_t currentRoll = 0;
		uint16_t currentHand = 0;
		uint16_t possibleHand = 0;

    bool retainDice[6]; 

  public:	
  
    void activate(StateMachine & machine) override;
    void update(StateMachine & machine) override;
    void render(StateMachine & machine) override;

    void removeElement(byte* array, uint8_t elementNo, uint8_t arrayLength);
    void isort(uint8_t *a, uint8_t n);
    uint16_t calculateScore(boolean checkForFarkle);

    uint8_t firstSelection();
    bool allDicePlayed();
    void clearHand();
    void renderScore(StateMachine & machine, int16_t score, uint8_t x, uint8_t y);

};

