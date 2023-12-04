#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <raylib.h>
#include <raymath.h>


  const int cellSize = 30;
  const int cellCount = 25;

  const Vector2 starting_position = Vector2{13, 7};
    
  const int screenWidth = cellSize * cellCount;
  const int screenHeight = screenWidth;
  const int offset = 75;
    
  const Color Green = Color{173, 204, 96, 255};
  const Color Dark_Green = Color{43, 51, 24, 255};

  enum Direction {LEFT, RIGHT, UP, DOWN};
  
  enum States {MENU, GAME, GAMEOVER, EXIT, CONTINUE};

  const Vector2 directions[4] = {
    Vector2{-1, 0}, Vector2{1, 0}, Vector2{0, -1}, Vector2{0, 1}
  };
  


