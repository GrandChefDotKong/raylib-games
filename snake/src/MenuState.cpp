#include "State.cpp"

class MenuState: public State {
private:
  int m_textSize;

public:
  MenuState(){
    m_textSize = MeasureText("Press Enter ...", 40);
  }

  virtual States Update() {
    if(IsKeyPressed(KEY_ENTER)) {
      return States::GAME;
    }

    if(IsKeyPressed(KEY_ESCAPE)) {
      return States::EXIT;
    }

    return States::CONTINUE;
  }

  virtual void Draw() {
    DrawText("Press Enter ...", (screenWidth/2) - (m_textSize/4), screenHeight/2, 40, Dark_Green);
  }

  virtual ~MenuState(){}
};