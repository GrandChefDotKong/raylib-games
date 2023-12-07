#include "Obstacle.cpp"

class Laser {
 private:
  Vector2 m_position;
  int m_width;
  int m_height;
  int m_speed;
  Direction m_direction;
  Color m_color;

 public: 
  Laser(Vector2 position, Direction direction, int speed = 3, int width = 2, int height = 15, Color color = WHITE): 
  m_position(position) ,m_direction(direction), m_speed(speed), m_width(width), m_height(height), m_color(color) {
  }

  void FixedUpdate() {
    switch (m_direction) {
    case UP:
      m_position.y -= m_speed;
      break;    
    case DOWN:
      m_position.y += m_speed;
      break;
    default:
      break;
    }
  }

  const Vector2 getPosition() {
    return m_position;
  }

  void Draw() {
    DrawRectangleRounded(
      Rectangle{m_position.x, m_position.y, (float)m_width, (float)m_height},
      0.5, 
      6,
      BLUE
    );
  }

  ~Laser() {

  }
};