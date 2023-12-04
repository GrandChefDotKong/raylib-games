#include "Snake.cpp"

class Food {
private:
  Vector2 m_position;
  Texture2D m_FoodTexture;
  Image m_FoodImage;
  float m_scale;

public:
  Food(std::string path): m_scale(1.0) {
    this->m_FoodImage = LoadImage(path.c_str());
    this->m_FoodTexture = LoadTextureFromImage(this->m_FoodImage);

    this->m_position.x = 5;
    this->m_position.y = 5;
  }

  const Vector2 getPosition() const {
    return this->m_position;
  }

  void generatePosition(const Snake* snake) {
    float x, y;

    do {
      x = GetRandomValue(0, cellCount - 1);
      y = GetRandomValue(0, cellCount - 1);
    } while(snake->ElementInDeque(Vector2{x, y}));

    this->m_position.x = x;
    this->m_position.y = y;
  }

  void FixedUpdate() {
    if(this->m_scale >= 1.1) {
      this->m_scale -= 0.1;
    } else {
      this->m_scale += 0.1;
    }
  }

  void Draw() {
    DrawTextureEx(
      this->m_FoodTexture,
      Vector2{ this->m_position.x * cellSize + offset,
               this->m_position.y * cellSize + offset},
      0,
      this->m_scale,
      WHITE
    );
  }

  ~Food() {
    UnloadImage(this->m_FoodImage);
    UnloadTexture(this->m_FoodTexture);
  }
};
