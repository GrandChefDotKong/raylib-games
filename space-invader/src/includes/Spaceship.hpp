#pragma once
#include "params.hpp"

class Spaceship {

private:
  
  Texture2D m_texture;
  Image m_image;
  Rectangle m_rectangle;
  Direction m_direction;
  float m_scale;
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







