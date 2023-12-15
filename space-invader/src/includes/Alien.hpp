#pragma once
#include "AnimationTree.hpp"

class Alien {

private:
  Texture2D* m_texture;
  Texture2D* m_texture2;
  AnimationTree* m_animationTree;
  Rectangle m_rectangle;
  Direction m_direction = RIGHT;
  Vector2 m_speed;

  bool m_isFiring = false;
  bool m_isAlive = true;

public:
  Alien(Texture2D* texture, Texture2D* texture2, Vector2 position, Vector2 speed);
  void Update();
  void FixedUpdate();

  const bool CheckCollision(Rectangle laser);
  const bool ShouldBeDeleted();
  const Rectangle getPosition();
  const Direction getDirection();

  void ChangeDirection(Direction direction);
  void Draw();
  
  ~Alien();
};

