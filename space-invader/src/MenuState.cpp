#include "./includes/MenuState.hpp"

  MenuState::MenuState(){
    m_textSize = MeasureText("Press Enter ...", 25);
  }

  States MenuState::Update() {
    if(IsKeyPressed(KEY_ENTER)) {
      return States::GAME;
    }

    if(IsKeyPressed(KEY_ESCAPE)) {
      return States::EXIT;
    }

    return States::CONTINUE;
  }

  void MenuState::Draw() {
    DrawText("Press Enter ...", 
      (SCREEN_WIDTH/2) - (m_textSize/4), 
      SCREEN_HEIGHT/2, 
      25, 
      Light_Green
    );
  }

  MenuState::~MenuState(){}


