#pragma once
#include "AnimationTree.hpp"
#include "params.hpp"

class Character {

private:
  Texture2D* m_texture;
  AnimationTree* m_animationTree;
  Rectangle m_rectangle;
  Direction m_direction = RIGHT;
  Vector2 m_speed;

  bool m_isFiring = false;
  bool m_isAlive = true;

public:
  Character(Texture2D* texture, Vector2 position, Vector2 speed);
  virtual void Update() = 0;
  virtual void FixedUpdate() = 0;

  const Rectangle getPosition();
  const Direction getDirection();

  void Draw();
  
  ~Character();
};

