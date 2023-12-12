#pragma once
#include "Alien.hpp"

class Aliens {

private:
  std::vector<Alien*> m_aliens;
  std::vector<Texture2D> m_textures;
  std::vector<Image> m_images;
  Direction m_direction = RIGHT;

  Vector2 m_speed;
  int m_cellSize = ALIENS_CELL_SIZE;

public:
  Aliens(Vector2 position);
  void Initiate(Vector2 position);
  const Vector2 Firing();
  bool CheckCollision(const Rectangle laser);
  void Update();
  void FixedUpdate();
  void Draw();
  ~Aliens();
};

