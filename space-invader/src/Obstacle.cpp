#include "Aliens.cpp"

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
    int columns, Color color = WHITE): 
    m_size(size), m_position(position), m_cellsize(cellsize), m_rows(rows), 
    m_columns(columns), m_color(color) {
      
      m_grid = new bool[size];
      for(int i(0); i < size; ++i) {
        m_grid[i] = grid[i];
      }
    }

    void Update() {

    }

    bool DestroyCell(const Rectangle position) {
      for(int i(0); i < m_size; ++i) {
        if(m_grid[i] && 
          position.x + position.width >= m_position.x+(i%m_columns)*m_cellsize && 
          position.x < m_position.x+(i%m_columns+1)*m_cellsize && 
          position.y >= m_position.y+(i/m_columns)*m_cellsize &&
          position.y < m_position.y+(i/m_columns+1)*m_cellsize
        ) {
          m_grid[i] = false;
          return true;
        }
      }

      return false;
    }

    void Draw() {
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

    ~Obstacle() {
      delete m_grid;
    }


};