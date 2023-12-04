#include "params.cpp" 

class Snake {
private:
  std::deque<Vector2> m_body;
  Direction m_direction;
  bool m_hasEaten;
  bool m_isDead;

public:
  Snake(): m_direction(DOWN), m_hasEaten(false), m_isDead(false) {
    this->m_body = {
      starting_position, 
      Vector2{starting_position.x, starting_position.y-1}, 
      Vector2{starting_position.x, starting_position.y -2}};
  }

  const Vector2 getHeadPosition() const {
    return this->m_body[0];
  }

  void Update() {

    if(IsKeyPressed(KEY_UP) && this->m_direction != DOWN) {
      this->m_direction = UP;
    }
    if(IsKeyPressed(KEY_DOWN) && this->m_direction != UP) {
      this->m_direction = DOWN;
    }
    if(IsKeyPressed(KEY_LEFT) && this->m_direction != RIGHT) {
      this->m_direction = LEFT;
    }
    if(IsKeyPressed(KEY_RIGHT) && this->m_direction != LEFT) {
      this->m_direction = RIGHT;
    }
  }

  void FixedUpdate() {
    if(!m_hasEaten) {
      this->m_body.pop_back();
    } else {
      this->m_hasEaten = false;
    }

    this->m_body.push_front(Vector2Add(m_body[0], directions[this->m_direction]));

    if(this->checkCollision()) {
      this->m_isDead = true;
    }
  }

  bool isDead() const {
    return this->m_isDead;
  }

  bool checkCollision() const {
    if(this->m_body[0].x < 0 || this->m_body[0].x * cellSize >= screenWidth 
    || this->m_body[0].y < 0 || this->m_body[0].y * cellSize >= screenHeight) {
      return true;
    }

    for(unsigned int i = 1; i < this->m_body.size(); ++i) {
      if(Vector2Equals(this->m_body[0], this->m_body[i])) {
        return true;
      }
    }

    return false;
  }

  void setHasEaten(bool hasEaten) {
    this->m_hasEaten = hasEaten;
  }

  bool ElementInDeque(Vector2 element) const {
  
    for (unsigned int i(0); i < this->m_body.size(); ++i){
      if(Vector2Equals(this->m_body[i], element)) {
        return true;
      }
    } 
    return false;
  }

  void Draw() {
    for (unsigned int i(0); i < this->m_body.size(); ++i){
      DrawRectangleRounded(
        Rectangle{this->m_body[i].x * cellSize + offset, this->m_body[i].y * cellSize + offset, (float)cellSize, (float)cellSize},
        0.5, 
        6,
        Dark_Green
      );
    }
  }
};