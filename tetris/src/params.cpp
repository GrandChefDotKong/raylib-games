#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <array>
#include <map>
#include <raylib.h>
#include <raymath.h>
    
  const int SCREEN_WIDTH = 500;
  const int SCREEN_HEIGHT = 600;
  const int OFFSET = 30;

  const int ROWS = 20;
  const int COLUMNS = 10;
  const int CELL_SIZE = 30;

  const Color DarkGrey = {26, 31, 40, 255};
  const Color Green = {47, 230, 23, 255};
  const Color Red = {232, 18, 18, 255};
  const Color Orange = {226, 116, 17, 255};
  const Color Yellow = {237, 234, 4, 255};
  const Color Purple = {166, 0, 247, 255};
  const Color Cyan = {21, 204, 209, 255};
  const Color Blue = {13, 64, 216, 255};
  const Color LightBlue = {59, 85, 162, 255};
  const Color DarkBlue = {44, 44, 127, 255};

  const Color Light_Green = Color{173, 204, 96, 255};
  const Color Dark_Green = Color{43, 51, 24, 255};

  const std::vector<Color> COLORS = {
      DarkGrey, Blue, Orange, Cyan, Yellow, Red, Purple, Green 
  };

  enum Direction {RIGHT, DOWN, LEFT};
  //enum Rotation {RIGHT, UP, DOWN, LEFT};
  
  enum States {MENU, GAME, GAMEOVER, EXIT, CONTINUE};

  enum TetrominoTypes {L = 1, J, I, O, S, T, Z};

  const int EMPTY = 0;

  struct position {
    int row;
    int column;
  };



