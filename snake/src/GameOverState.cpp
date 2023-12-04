#include "GameState.cpp"

class GameOverState: public State {

private:
  int m_textSize;

public:
  GameOverState(){
    m_textSize = MeasureText("Game Over ...", 50);
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
    DrawText("Game Over ...", (screenWidth/2) - (m_textSize/4), screenHeight/2, 50, Dark_Green);
    DrawText("Press Enter to restrart or Escape to quite.", offset-5, offset+screenWidth+10, 20, Dark_Green);
  }

  virtual ~GameOverState(){}
};