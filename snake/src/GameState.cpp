#include "Timer.cpp"

class GameState: public State {

private:
  Food* m_food;
  Snake* m_snake;
  std::vector<Hole*> m_holes;
  unsigned int m_score;
  Timer* m_snakeTimer;
  Timer* m_holeTimer;

  unsigned short m_grid[cellCount*cellCount] = {0};

public:
  GameState(): m_score(0) {
    m_food = new Food("ressources/food.png");
    m_snake = new Snake();
    m_holes.push_back(new Hole());

    m_snakeTimer = new Timer(0.2);
    m_holeTimer = new Timer(5.0);
  }

  bool checkCollisionSnakeFood() {
    if(this->m_snake->getHeadPosition().x == this->m_food->getPosition().x && 
    this->m_snake->getHeadPosition().y == this->m_food->getPosition().y) {
      return true;
    }

    return false;
  }
  
  bool checkCollisionSnakeHole() {
    for (auto& hole : this->m_holes) {
      if(this->m_snake->getHeadPosition().x == hole->getPosition().x && 
      this->m_snake->getHeadPosition().y == hole->getPosition().y) {
        return true;
      }
    }

    return false;
  }

  void generateNewHole() {
     float x, y;

    do {
      x = GetRandomValue(0, cellCount - 1);
      y = GetRandomValue(0, cellCount - 1);
    } while(
      m_snake->ElementInDeque(Vector2{x, y}) ||
      (m_food->getPosition().x == x && m_food->getPosition().y == y) ||
      this->ElementInVector(Vector2{x, y})
    );

    this->m_holes.push_back(new Hole(x, y));
  }

  bool ElementInVector(Vector2 position) {
    for (auto& hole : this->m_holes) {
      if(hole->getPosition().x == position.x && 
      hole->getPosition().y == position.y) {
        return true;
      }
    }

    return false;
  }

  virtual States Update() {
    this->m_snake->Update();

    if(this->m_snake->isDead()) {
      return States::GAMEOVER;
    }

    if(this->m_snakeTimer->eventTriggered()) {
      this->m_food->FixedUpdate();
      this->m_snake->FixedUpdate();
    }

    if(this->m_holeTimer->eventTriggered()) {
      this->generateNewHole();
    }

    if(this->checkCollisionSnakeFood()) {
      this->m_food->generatePosition(this->m_snake);
      this->m_snake->setHasEaten(true);
      this->m_score += 10;
      double newInterval = this->m_snakeTimer->getInterval() - 0.005;

      if(newInterval < 0.05) {
        newInterval = 0.05;
      }

      this->m_snakeTimer->setInterval(newInterval);
    }

    if(this->checkCollisionSnakeHole()) {
      return States::GAMEOVER;
    }

    return States::CONTINUE;
  }

  virtual void Draw() {
    DrawText("Retro Snake++", offset-5, 20, 40, Dark_Green);
    DrawText(TextFormat("Score : %i", this->m_score), offset-5, offset+screenWidth+10, 40, Dark_Green);
    
    this->m_food->Draw();
    
    for (auto& hole : this->m_holes) {
      hole->Draw();
    }
    
    this->m_snake->Draw();
  }

  virtual ~GameState(){
    delete this->m_food;
    delete this->m_snake;
    for (auto& hole : this->m_holes) {
      delete hole;
    }
    delete m_snakeTimer;
    delete m_holeTimer;
  }
};