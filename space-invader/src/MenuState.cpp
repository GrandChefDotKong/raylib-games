#include "State.cpp"

class MenuState: public State {
private:
  int m_textSize;

public:
  MenuState(){
    m_textSize = MeasureText("Press Enter ...", 25);
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
    DrawText("Press Enter ...", 
      (SCREEN_WIDTH/2) - (m_textSize/4), 
      SCREEN_HEIGHT/2, 
      25, 
      Light_Green
    );
  }

  virtual ~MenuState(){}
};