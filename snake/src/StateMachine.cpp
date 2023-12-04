#include "GameOverState.cpp"

class StateMachine {
  private:
    State* m_currentState;
    States m_newState;

  public:
    StateMachine() {
      InitWindow(2 * offset + screenWidth, 2 * offset + screenHeight, "My first RAYLIB program!");
      SetTargetFPS(60);
    }

    void Run() {
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

    void Update() {
      m_newState = m_currentState->Update();
    }

    void Draw() {
      BeginDrawing();
      ClearBackground(Green);
      DrawRectangleLinesEx(Rectangle{offset-5, offset-5, screenWidth+10, screenHeight+10}, 5, Dark_Green);

      m_currentState->Draw();

      EndDrawing();
    }

    virtual ~StateMachine() {
      delete m_currentState;
      std::cout << "current state deleted : OK" << std::endl;
      CloseWindow();
    }
};
