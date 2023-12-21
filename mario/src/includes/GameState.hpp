#pragma once
#include "State.hpp"
#include "params.hpp"
#include "Obstacle.hpp"
#include "Laser.hpp"
#include "Spaceship.hpp"
#include "Timer.hpp"
#include "AssetsManager.hpp"
#include "Parallax.hpp"

class GameState: public State {

private:
  unsigned int m_score;
  bool m_gameOver;
  
  Timer* m_speed;
  
public:
  GameState();
  virtual States Update();
  virtual void FixedUpdate();
  void LoadingAssets();
  virtual void Draw();
  virtual ~GameState();
};

