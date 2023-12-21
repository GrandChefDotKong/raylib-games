#pragma once
#include "State.hpp"

class GameOverState: public State {

private:
  int m_textSize;

public:
  GameOverState();
  virtual void Draw();
  virtual States Update();
  virtual ~GameOverState();
};