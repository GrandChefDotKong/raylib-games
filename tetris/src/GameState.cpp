#include "MenuState.cpp"

class GameState: public State {

private:
  unsigned int m_score;
  Grid* m_grid;
  Tetromino* m_currentTetromino;
  Tetromino* m_nextTetromino;
  Timer* m_speed;
  std::vector<TetrominoTypes> m_tetrominos;
  bool m_gameOver;

public:
  GameState(): m_score(0) {
    m_grid = new Grid(ROWS, COLUMNS, CELL_SIZE);
    m_tetrominos = GetAllTetrominos();
    m_currentTetromino = new Tetromino(this->GetRandomTetromino());
    m_nextTetromino = new Tetromino(this->GetRandomTetromino());
    m_speed = new Timer(0.4);

  }

  virtual States Update() {
    if(m_gameOver) {
      return States::GAMEOVER;
    }

    this->HandleInput();

    if(m_speed->eventTriggered()) {
      if(this->CanTetrominoMove(Direction::DOWN)) {
        m_currentTetromino->Move(Direction::DOWN);
      } else {
        this->AddTetrominoToGrid();
      }
    }

    return States::CONTINUE;
  }

  virtual void Draw() {
    m_grid->Draw();
    this->DrawUI();
    m_currentTetromino->Draw(OFFSET, OFFSET);
  }

  std::vector<TetrominoTypes> GetAllTetrominos() {
    return {L, J, I, O, S, T, Z};
  }

  TetrominoTypes GetRandomTetromino() {
    if (m_tetrominos.empty()) {
      m_tetrominos = GetAllTetrominos();
    }

    int randomIndex = rand() % m_tetrominos.size();
    TetrominoTypes tetromino = m_tetrominos[randomIndex];
    m_tetrominos.erase(m_tetrominos.begin() + randomIndex);
    return tetromino;
  }

  void DrawUI() {
    DrawText("Score :", 
      SCREEN_WIDTH - 110, SCREEN_HEIGHT/4, 25, Dark_Green
    );

    DrawRectangleRounded(
      Rectangle{SCREEN_WIDTH - 120, SCREEN_HEIGHT/4+40, 100, 40}, 0.3, 6, Dark_Green
    );

    DrawText(
      TextFormat("%i", m_score), SCREEN_WIDTH - 100, SCREEN_HEIGHT/4+50, 20, Light_Green
    );
    
    DrawText("Next :", 
      SCREEN_WIDTH - 110, SCREEN_HEIGHT/2, 25, Dark_Green
    );
    
    DrawRectangleRounded(
      Rectangle{SCREEN_WIDTH - 140, SCREEN_HEIGHT/2+40, 160, 100}, 0.3, 6, Dark_Green
    );

    m_nextTetromino->Draw(SCREEN_WIDTH - 210, SCREEN_HEIGHT/2+60);
  }

  void HandleInput() {
    int keyPressed = GetKeyPressed();

    switch (keyPressed) {
      case KEY_LEFT:
        if(CanTetrominoMove(Direction::LEFT)) {
          m_currentTetromino->Move(Direction::LEFT);
        }
      break;
      case KEY_RIGHT:
        if(CanTetrominoMove(Direction::RIGHT)) {
          m_currentTetromino->Move(Direction::RIGHT);
        }
      break;
      case KEY_DOWN:
        if(CanTetrominoMove(Direction::DOWN)) {
          m_currentTetromino->Move(Direction::DOWN);
        }
      break;
      case KEY_UP:
        m_currentTetromino->Rotate();
        if(!this->IsTetrominoFitting()) {
          m_currentTetromino->UndoRotation();
        }
      break;
    }
  }

  void AddTetrominoToGrid() {
    std::vector<position> tiles = m_currentTetromino->GetCellPositions();
    for (position item : tiles) {
      m_grid->AddToGrid(item.row*COLUMNS+item.column, m_currentTetromino->GetType());
    }

    delete m_currentTetromino;
    m_currentTetromino = m_nextTetromino;
    m_nextTetromino = new Tetromino(GetRandomTetromino());

    if(!IsTetrominoFitting()) {
      m_gameOver = true;
    }

    int rowsCleared = m_grid->CheckLines();

    m_score += rowsCleared * 10;
    if(rowsCleared == 4) {
      m_score += 20;
    }
  }

  bool CanTetrominoMove(Direction direction) {
    int row = 0;
    int column = 0;

    switch (direction) {
      case LEFT:
        column--;
      break;
      case RIGHT:
        column++;
      break;
      case DOWN:
        row++;
      break;
    }
    
    if(IsTetrominoFitting(row, column)) {
      return true;
    } 
     
    return false;    
  }

  bool IsTetrominoFitting(int row = 0, int column = 0) {
    std::vector<position> tiles = m_currentTetromino->GetCellPositions();
    for (position item : tiles) {
      if(!m_grid->IsCellEmpty(item.row+row, item.column+column) ||
      m_grid->IsCellOutsideGrid(item.row+row, item.column+column)) {
        return false;
      }
    }
    return true;
  }

  virtual ~GameState(){
    delete m_grid;
    delete m_currentTetromino;
    delete m_speed;
  }
};
