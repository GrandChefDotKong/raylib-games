#include "./includes/GameOverState.hpp"


GameOverState::GameOverState(){
  m_textSize = MeasureText("Game Over ...", 50);
}

States GameOverState::Update() {
  if(IsKeyPressed(KEY_ENTER)) {
    return States::GAME;
  }

  if(IsKeyPressed(KEY_ESCAPE)) {
    return States::EXIT;
  }

  return States::CONTINUE;
}

void GameOverState::Draw() {
  DrawText("Game Over ...", (SCREEN_WIDTH/2)-(m_textSize/2)+OFFSET, SCREEN_HEIGHT/2, 50, Light_Green);
  DrawText("Press Enter to restrart or Escape to quite.", OFFSET+10, SCREEN_HEIGHT+OFFSET+10, 15, Light_Green);
}

GameOverState::~GameOverState(){

}

