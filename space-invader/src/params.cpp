#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <array>
#include <map>
#include <raylib.h>
#include <raymath.h>
    
  const int SCREEN_WIDTH = 750;
  const int SCREEN_HEIGHT = 700;
  const int OFFSET = 30;
// Obstacle
  const int NUMBER_OBSTACLE = 5;
  const int ROWS = 13;
  const int COLUMNS = 23;
  const int CELL_SIZE = 3;
// LASER
  const int LASER_WIDTH = 3;
  const int LASER_HEIGHT = 15;
  const int LASER_SPEED = 3;
// ALIEN
  const int ALIENS_LINE = 5;
  const int ALIENS_COLUMNS = 11;
  const int ALIENS_CELL_SIZE = 55;

  const Color Light_Green = Color{173, 204, 96, 255};
  const Color Dark_Green = Color{43, 51, 24, 255};

  enum Direction {IDDLE, RIGHT, DOWN, LEFT, UP};
  
  enum States {MENU, GAME, GAMEOVER, EXIT, CONTINUE};

  const bool obstacle_grid[299] = {
    0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,
    0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,
    0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,
    0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,
    1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,
    1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,
  };





