#include "Tetromino.cpp"

class Grid {
private:
  int m_rows, m_columns;
  int* m_grid;
  int m_cellSize;
  std::vector<Color> m_colors;

public:
  Grid(int rows, int columns, int cellSize): 
  m_rows(rows), m_columns(columns), m_cellSize(cellSize) {

    m_grid = new int[m_rows*m_columns]{EMPTY};
    m_colors = COLORS; 
  }

  void AddToGrid(int index,TetrominoTypes type) {
    m_grid[index] = type;
  }

  void Initialize() {

  }

  void Draw() {
    for (int i = 0; i < m_columns*m_rows; ++i) {
      int cellValue = m_grid[i];
      DrawRectangle(
        (i%m_columns)*m_cellSize+1+OFFSET,
        (i/m_columns)*m_cellSize+1+OFFSET,
        m_cellSize-1, m_cellSize-1,
        m_colors[cellValue]
      );
    }    
  }

  bool IsCellEmpty(int row, int column) {
    if(m_grid[row*m_columns+column] == EMPTY) {
      return true;
    }

    return false;
  }

  int CheckLines() {

    int lines = 0;
    int rowIndex = -1;
    int counter = 4;
  
    for (int i = m_rows-1; i >= 0; --i) {
      int columns = 0;
      for (int j = 0; j < m_columns; ++j) {
        if(m_grid[i*m_columns+j] != EMPTY) {
          columns++;
        }
      }
      
      if(columns == m_columns) {

        if(lines == 0) {
          rowIndex = i;
        }

        lines++;
      }

      if(lines != 0) {
        counter--;
        if(counter == 0) {
          this->DeleteLines(rowIndex, lines);
          return lines;
        }
      }
    }
    
    return lines;
  }

  void DeleteLines(int startIndex, int numberOflines) {
    for (int i = startIndex; i >= 0; --i) {
      for(int j = 0; j < m_columns; ++j) {
        if(i <= numberOflines) {
          m_grid[(i*m_columns)+j] = EMPTY;
        } else {
          m_grid[(i*m_columns)+j] = m_grid[(i-numberOflines)*m_columns+j];
        }
      }
    }
  }

  bool IsCellOutsideGrid(int row, int column) {
    if (row >= 0 && row < m_rows && column >= 0 && column < m_columns) {
      return false;
    }

    return true;
  }

  ~Grid() {
    delete m_grid;
  }
};

