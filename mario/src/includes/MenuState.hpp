#pragma once
#include "State.hpp"

class MenuState: public State {
private:
  int m_textSize;

public:
  MenuState();
  virtual void Draw();
  virtual States Update();
  virtual ~MenuState();
};

