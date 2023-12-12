#pragma once
#include "AnimationTree.hpp"

class Spaceship {

private:
  
  AnimationTree* m_animationTree;
  Texture2D m_texture;
  Rectangle m_rectangle;
  Direction m_direction;
  int m_speed;

  bool m_isFiring;
  bool m_isAlive;

public:
  Spaceship(std::string path, int speed = 2);
  void Update();
  void FixedUpdate();
  const bool isFiring();
  void stopFiring();  
  const Rectangle getPosition();
  ~Spaceship();
  void Draw();
};







