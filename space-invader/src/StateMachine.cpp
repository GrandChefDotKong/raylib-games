#include "./includes/StateMachine.hpp"

    StateMachine::StateMachine() {
      InitWindow(2*OFFSET+SCREEN_WIDTH , 2*OFFSET+SCREEN_HEIGHT, 
      "Space Invader++");
      SetTargetFPS(60);
    }

    void StateMachine::Run() {
      m_newState = States::CONTINUE;
      m_currentState = new MenuState();


      while(WindowShouldClose() == false) {

        this->Update();
        this->Draw();

        switch (m_newState) {
          case CONTINUE:
            break;
          case EXIT:
            return;
          case MENU:
            delete m_currentState;
            m_currentState = new MenuState();
            break;
          case GAME:
            delete m_currentState;
            m_currentState = new GameState();
            break;
          case GAMEOVER:
            delete m_currentState;
            m_currentState = new GameOverState();
            break;
        }
      }
    }

    void StateMachine::Update() {
      m_newState = m_currentState->Update();
    }

    void StateMachine::Draw() {
      BeginDrawing();
      ClearBackground(Dark_Green);
      
      DrawRectangleLinesEx(
        Rectangle{OFFSET-5, OFFSET-5, SCREEN_WIDTH+10, SCREEN_HEIGHT+10}, 2, Light_Green
      );

      m_currentState->Draw();
      EndDrawing();
    }

    StateMachine::~StateMachine() {
      delete m_currentState;
      CloseWindow();
    }

