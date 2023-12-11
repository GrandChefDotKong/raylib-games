#pragma once
#include "params.hpp"

class Alien {

private:
  Texture2D* m_texture;
  Rectangle m_rectangle;
  Direction m_direction = RIGHT;

  float m_scale = 1;
  Vector2 m_speed;

  bool m_isFiring = false;
  bool m_isAlive = true;

public:
  Alien(Texture2D* texture, Vector2 position, Vector2 speed);
  void FixedUpdate();
  bool CheckCollision(Rectangle laser);
  const Rectangle getPosition();
  const Direction getDirection();
  void ChangeDirection(Direction direction);
  void Draw();
  
  ~Alien();
};

