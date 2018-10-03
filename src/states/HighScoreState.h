#pragma once

#include "../utils/GameContext.h"
#include "../utils/GameState.h"
#include "../utils/Enums.h"
#include "../images/Images.h"
#include "BaseState.h"

class HighScoreState : public BaseState {

  private:

    int8_t yLeft = 0;
    int8_t yRight = 64;
    
  public:	
  
    void activate(StateMachine & machine) override;
    void update(StateMachine & machine) override;
    void render(StateMachine & machine) override;


};

