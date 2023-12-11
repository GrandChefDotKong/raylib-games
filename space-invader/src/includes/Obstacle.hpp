#pragma once
#include "params.hpp"

class Obstacle {
private:
  Vector2 m_position;
  Color m_color;

  bool* m_grid;
  
  int m_size;
  int m_cellsize;
  int m_rows;
  int m_columns;

public:
  Obstacle(int size, const bool grid[], Vector2 position, int cellsize, int rows, 
  int columns, Color color = WHITE);
  
  void Update();
  bool DestroyCell(const Rectangle position);
  void Draw();
  ~Obstacle();
};


