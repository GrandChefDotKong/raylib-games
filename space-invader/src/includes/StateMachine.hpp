#pragma once
#include "GameOverState.hpp"
#include "MenuState.hpp"
#include "GameState.hpp"

class StateMachine {
  private:
    State* m_currentState;
    States m_newState;

  public:
    StateMachine();

    void Run();
    void Update();
    void Draw();
    virtual ~StateMachine();
};

