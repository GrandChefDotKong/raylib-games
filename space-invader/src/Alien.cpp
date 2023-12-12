#include "./includes/Alien.hpp"

Alien::Alien(Texture2D* texture, Vector2 position, Vector2 speed):
m_texture(texture), m_speed(speed)  {
  m_rectangle.x = position.x;
  m_rectangle.y = position.y;
  m_rectangle.width = 48;
  m_rectangle.height = 48;

  m_animation = Animation(*m_texture);
  m_animation.AddFrames((m_texture->width/16), Rectangle{0, 0, 16, 16}, 16);
  m_animation.setInterval(0.2);
  m_animation.setIsLoop(true);
  m_animation.Start();
}

void Alien::Update() {
  m_animation.Update();
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
  m_animation.Draw(m_rectangle);
}

Alien::~Alien() {}

