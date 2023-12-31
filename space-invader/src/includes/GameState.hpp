#pragma once
#include "State.hpp"
#include "params.hpp"
#include "Obstacle.hpp"
#include "Laser.hpp"
#include "Aliens.hpp"
#include "Spaceship.hpp"
#include "Timer.hpp"
#include "AssetsManager.hpp"
#include "Parallax.hpp"

class GameState: public State {

private:
  unsigned int m_score;
  bool m_gameOver;
  
  Timer* m_speed;
  Timer* m_firingSpeed;

  Spaceship* m_spaceship;
  Aliens* m_aliens;
  Parallax m_parallax;
  std::vector<Laser*> m_lasers;
  std::vector<Obstacle*> m_obstacles;
  
public:
  GameState();
  virtual States Update();
  virtual void FixedUpdate();
  bool HandleCollision(Laser* laser);
  void GenerateLaser();
  void LoadingAssets();
  virtual void Draw();
  virtual ~GameState();
};

