#include "Timer.cpp"

class Obstacle {
  private:
    Vector2 m_position;
    Color m_color;
    bool* m_grid;
    int m_size;
    int m_cellsize = CELL_SIZE;
    int m_rows = ROWS;
    int m_columns = COLUMNS;

  public:
    Obstacle(int size, const bool grid[], Vector2 position, Color color = WHITE): 
    m_size(size), m_position(position), m_color(color) {
      m_grid = new bool[size];
      for(int i(0); i < size; ++i) {
        m_grid[i] = grid[i];
      }
    }

    void Update() {

    }

    bool DestroyCell(Vector2 position) {
      for(int i(0); i < m_size; ++i) {
        if(m_grid[i] && 
          position.x >= m_position.x+(i%m_columns)*m_cellsize && 
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