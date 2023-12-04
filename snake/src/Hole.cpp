#include "Food.cpp"

class Hole {
private:
  Vector2 m_position;

public:
  Hole() {
    this->m_position.x = 20;
    this->m_position.y = 4;
  }

  Hole(float x, float y): m_position(Vector2{x, y}) {

  } 

  const Vector2 getPosition() const {
    return this->m_position;
  }

  void FixedUpdate() {
  }

  void Draw() {
    DrawRectangle(
      this->m_position.x * cellSize + offset,
      this->m_position.y * cellSize + offset,
      cellSize, cellSize, BLACK
    );
  }

  ~Hole() {
  }
};
