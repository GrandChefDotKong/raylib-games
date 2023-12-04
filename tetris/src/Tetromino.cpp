#include "Tetrominos.cpp"

class Tetromino {
protected:
  int m_cellSize;
  int m_rotationState;
  int m_rowOffset;
  int m_columnOffset;
  TetrominoTypes m_type;
  std::map<int, std::vector<position>> m_cells;

public:
  Tetromino(TetrominoTypes type) {
    m_type = type;
    m_cellSize = 30;
    m_rotationState = 0;
    m_rowOffset = 0;
    m_columnOffset = 0;

    const TetrominoData data = TetrominoCollection.at(type);

    m_cells = data.cells;

    this->Move(data.startPosition.row, data.startPosition.column);
  }

  TetrominoTypes GetType() {
    return m_type;
  }

  virtual void Draw(int offsetX, int offsetY) {
    std::vector<position> tiles = GetCellPositions();

    for (position item : tiles) {
      DrawRectangle(
        item.column * m_cellSize + offsetX, 
        item.row * m_cellSize + offsetY, 
        m_cellSize - 1, m_cellSize - 1,
        COLORS[m_type]);
    }
  }

  void Move(Direction direction) {

    switch (direction) {
    case LEFT:
      m_columnOffset--;
      break;
    case RIGHT:
      m_columnOffset++;
      break;
    case DOWN:
      m_rowOffset++;
      break;
    }
  }

  void Move(int rows, int columns) {
    m_rowOffset += rows;
    m_columnOffset += columns;
  }

  std::vector<position> GetCellPositions()
  {
    std::vector<position> tiles = m_cells[m_rotationState];
    std::vector<position> movedTiles;

    for (position item : tiles) {
      position newPos;

      newPos.row = item.row + m_rowOffset;
      newPos.column = item.column + m_columnOffset;

      movedTiles.push_back(newPos);
    }

    return movedTiles;
  }

  void Rotate() {
    m_rotationState++;
    if (m_rotationState == (int)m_cells.size()) {
      m_rotationState = 0;
    }
  }

  void UndoRotation() {
    m_rotationState--;

    if (m_rotationState == -1) {
      m_rotationState = m_cells.size() - 1;
    }
  }
};

