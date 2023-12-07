#include "Laser.cpp"

class Spaceship {

private:
  
  Texture2D m_texture;
  Image m_image;
  Vector2 m_position;
  Direction m_direction;
  int m_offset;
  float m_scale;
  int m_speed;

  bool m_isFiring;
  bool m_isAlive;

public:
  Spaceship(std::string path, int speed = 2): 
  m_speed(speed), m_isFiring(false), m_isAlive(true) {

    this->m_image = LoadImage(path.c_str());
    this->m_texture = LoadTextureFromImage(this->m_image);

    m_position = Vector2{SCREEN_WIDTH/2, SCREEN_HEIGHT};
  }
  
  void Update() {

    if(IsKeyUp(KEY_SPACE)) {
      m_isFiring = false;
    }

    if(IsKeyUp(KEY_LEFT) && IsKeyUp(KEY_RIGHT)) {
      m_direction = IDDLE;
    }

    if(IsKeyDown(KEY_LEFT)) {
      this->m_direction = LEFT;
    }

    if(IsKeyDown(KEY_RIGHT)) {
      this->m_direction = RIGHT;
    }

    if(IsKeyPressed(KEY_SPACE)) {
      m_isFiring = true;
    }
  }

  void FixedUpdate() {
    switch (m_direction) {
      case IDDLE:
        break;
      case LEFT:
        m_position.x -= m_speed;
      break;
      case RIGHT:
        m_position.x += m_speed;
      break;
    }
  }

  bool isFiring() {
    return m_isFiring;
  }

  void stopFiring() {
    m_isFiring = false;
  }
  
  Vector2 getPosition() {
    return m_position;
  }

  Vector2 getDimension() {
    return Vector2{(float)m_texture.width, (float)m_texture.height};
  }

  ~Spaceship() {
    UnloadImage(this->m_image);
    UnloadTexture(this->m_texture);
  }

  void Draw() {
    DrawTextureEx(
      this->m_texture,
      Vector2{ this->m_position.x + m_offset, this->m_position.y + m_offset},
      0,
      1,
      WHITE
    );
  }
};







