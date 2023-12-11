#include "./includes/Laser.hpp"

  Laser::Laser(Vector2 position, Direction direction, Color color): 
  m_direction(direction), m_color(color) {

    m_rectangle = Rectangle{position.x, position.y, LASER_WIDTH, LASER_HEIGHT};
  }

  void Laser::FixedUpdate() {
    switch (m_direction) {
    case UP:
      m_rectangle.y -= m_speed;
      break;    
    case DOWN:
      m_rectangle.y += m_speed;
      break;
    default:
      break;
    }
  }

  const Rectangle Laser::getPosition() {
    return m_rectangle;
  }

  const Direction Laser::getDirection() {
    return m_direction;
  }

  void Laser::Draw() {
    DrawRectangleRounded(
      m_rectangle,
      0.5, 
      6,
      m_color
    );
  }

  Laser::~Laser() {
  }

  