#include "Grid.cpp"

class State {

public:
  State(){}

  virtual States Update() = 0;
  virtual void Draw() = 0;

  virtual ~State(){}
};