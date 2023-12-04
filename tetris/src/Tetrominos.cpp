#include "Timer.cpp"

struct TetrominoData {
  std::map<int, std::vector<position>> cells;
  position startPosition;
  
};

  const TetrominoData LTetromino = {
    {
      {0, {position{0, 2}, position{1, 0}, position{1, 1}, position{1, 2}}},
      {1, {position{0, 1}, position{1, 1}, position{2, 1}, position{2, 2}}}, 
      {2, {position{1, 0}, position{1, 1}, position{1, 2}, position{2, 0}}}, 
      {3, {position{0, 0}, position{0, 1}, position{1, 1}, position{2, 1}}}
    },
    position{0, 3}
  };
  
  const TetrominoData JTetromino = {
    {
      {0, {position{0, 0}, position{1, 0}, position{1, 1}, position{1, 2}}},
      {1, {position{0, 1}, position{0, 2}, position{1, 1}, position{2, 1}}}, 
      {2, {position{1, 0}, position{1, 1}, position{1, 2}, position{2, 2}}}, 
      {3, {position{0, 1}, position{1, 1}, position{2, 0}, position{2, 1}}}
    },
    position{0, 3}
  };

  const TetrominoData ITetromino = {
    {
      {0, {position{1, 0}, position{1, 1}, position{1, 2}, position{1, 3}}}, 
      {1, {position{0, 2}, position{1, 2}, position{2, 2}, position{3, 2}}}, 
      {2, {position{2, 0}, position{2, 1}, position{2, 2}, position{2, 3}}}, 
      {3, {position{0, 1}, position{1, 1}, position{2, 1}, position{3, 1}}}, 
    },
    position{-1, 3}
  };

  const TetrominoData OTetromino = {
    {
      {0, {position{0, 0}, position{0, 1}, position{1, 0}, position{1, 1}}},
    },
    position{0, 4}
  };  

  const TetrominoData STetromino = {
    {
      {0, {position{0, 1}, position{0, 2}, position{1, 0}, position{1, 1}}}, 
      {1, {position{0, 1}, position{1, 1}, position{1, 2}, position{2, 2}}}, 
      {2, {position{1, 1}, position{1, 2}, position{2, 0}, position{2, 1}}}, 
      {3, {position{0, 0}, position{1, 0}, position{1, 1}, position{2, 1}}}, 
    },
    position{0, 3}
  };

  const TetrominoData TTetromino = {
    {
      {0, {position{0, 1}, position{1, 0}, position{1, 1}, position{1, 2}}}, 
      {1, {position{0, 1}, position{1, 1}, position{1, 2}, position{2, 1}}}, 
      {2, {position{1, 0}, position{1, 1}, position{1, 2}, position{2, 1}}}, 
      {3, {position{0, 1}, position{1, 0}, position{1, 1}, position{2, 1}}}, 
    },
    position{0, 3}
  };

  const TetrominoData ZTetromino = {
    {
      {0, {position{0, 0}, position{0, 1}, position{1, 1}, position{1, 2}}}, 
      {1, {position{0, 2}, position{1, 1}, position{1, 2}, position{2, 1}}}, 
      {2, {position{1, 0}, position{1, 1}, position{2, 1}, position{2, 2}}}, 
      {3, {position{0, 1}, position{1, 0}, position{1, 1}, position{2, 0}}}, 
    },
    position{0, 3}
  };
  
  const std::map<TetrominoTypes, TetrominoData> TetrominoCollection = {
    {TetrominoTypes::L, LTetromino},
    {TetrominoTypes::J, JTetromino},
    {TetrominoTypes::I, ITetromino},
    {TetrominoTypes::O, OTetromino},
    {TetrominoTypes::S, STetromino},
    {TetrominoTypes::T, TTetromino},
    {TetrominoTypes::Z, ZTetromino},
  };