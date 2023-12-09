#include "Obstacle.cpp"

class Laser {

private:
  int m_speed = LASER_SPEED;
  Rectangle m_rectangle;
  Direction m_direction;
  Color m_color;

public: 
  Laser(Vector2 position, Direction direction, Color color = WHITE): 
  m_direction(direction), m_color(color) {

    m_rectangle = Rectangle{position.x, position.y, LASER_WIDTH, LASER_HEIGHT};
  }

  void FixedUpdate() {
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

  const Rectangle getPosition() {
    if(m_direction == UP) {
      return m_rectangle;
    }

    return Rectangle{
      m_rectangle.x, 
      m_rectangle.y+m_rectangle.height, 
      m_rectangle.width, 
      -m_rectangle.height
    };
  }

  const Direction getDirection() {
    return m_direction;
  }

  void Draw() {
    DrawRectangleRounded(
      m_rectangle,
      0.5, 
      6,
      BLUE
    );
  }

  ~Laser() {
  }
};