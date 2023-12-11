#pragma once
#include "params.hpp"

class Laser {

private:
  int m_speed = LASER_SPEED;
  Rectangle m_rectangle;
  Direction m_direction;
  Color m_color;

public: 
  Laser(Vector2 position, Direction direction, Color color = WHITE);
  void FixedUpdate();
  const Rectangle getPosition();
  const Direction getDirection();
  void Draw();
  ~Laser();
};