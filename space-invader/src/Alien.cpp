#include "./includes/Alien.hpp"

Alien::Alien(Texture2D* texture, Vector2 position, Vector2 speed):
m_texture(texture), m_speed(speed)  {
  m_rectangle.x = position.x;
  m_rectangle.y = position.y;
  m_rectangle.width = m_texture->width;
  m_rectangle.height = m_texture->height;
    
}

void Alien::FixedUpdate() {
  switch (m_direction) {
    case IDDLE:
      break;
    case LEFT:
      m_rectangle.x -= m_speed.x;
    break;
    case RIGHT:
      m_rectangle.x += m_speed.x;
    break;
    case DOWN:
      m_rectangle.y += m_speed.y;
    break;
  }
}

bool Alien::CheckCollision(Rectangle laser) {
  if(CheckCollisionRecs(m_rectangle, laser)) {
    m_isAlive = false;
    return true;
  }

  return false;
}

const Rectangle Alien::getPosition() {
  return m_rectangle;
}

const Direction Alien::getDirection() {
  return m_direction;
}

void Alien::ChangeDirection(Direction direction) {
  m_direction = direction;
}

void Alien::Draw() {
  DrawTextureEx(
    *m_texture,
    Vector2{m_rectangle.x, m_rectangle.y},
    0,
    m_scale,
    WHITE
  );
}

Alien::~Alien() {}

