#include "./includes/Obstacle.hpp"

Obstacle::Obstacle(int size, const bool grid[], Vector2 position, int cellsize, int rows, 
int columns, Color color): 
m_size(size), m_position(position), m_cellsize(cellsize), m_rows(rows), 
m_columns(columns), m_color(color) {
  
  m_grid = new bool[size];
  for(int i(0); i < size; ++i) {
    m_grid[i] = grid[i];
  }
}

void Update() {

}

bool Obstacle::DestroyCell(const Rectangle position) {
  Rectangle cellRectangle;
  cellRectangle.width = m_cellsize;
  cellRectangle.height = m_cellsize;

  for(int i(0); i < m_size; ++i) {
    cellRectangle.x = m_position.x+(i%m_columns)*m_cellsize;
    cellRectangle.y = m_position.y+(i/m_columns)*m_cellsize;

    if(m_grid[i] && CheckCollisionRecs(cellRectangle, position)) {
      m_grid[i] = false;
      return true;
    }
  }

  return false;
}

void Obstacle::Draw() {
  for(int i(0); i < m_size; ++i) {
    if(m_grid[i]) {
      DrawRectangle(
        m_position.x+(i%m_columns*m_cellsize), 
        m_position.y+(i/m_columns*m_cellsize), 
        m_cellsize, 
        m_cellsize, 
        m_color
      ); 
    }
  }
}

Obstacle::~Obstacle() {
  delete m_grid;
}

