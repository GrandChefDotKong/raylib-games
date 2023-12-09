#include "MenuState.cpp"

class GameState: public State {

private:
  unsigned int m_score;
  bool m_gameOver;
  
  Timer* m_speed;
  Timer* m_firingSpeed;

  Spaceship* m_spaceship;
  Aliens* m_aliens;
  std::vector<Laser*> m_lasers;
  std::vector<Obstacle*> m_obstacles;
  
public:
  GameState(): m_score(0), m_gameOver(false) {
    m_spaceship = new Spaceship("ressources/spaceship.png");

    m_speed = new Timer(0.02);
    m_firingSpeed = new Timer(0.1);

    for(int i(1); i <= NUMBER_OBSTACLE; ++i) {
      m_obstacles.push_back(
        new Obstacle(
          ROWS*COLUMNS, obstacle_grid, Vector2{(float)i*100+50, 620}, CELL_SIZE, ROWS, COLUMNS, RED
        )
      );
    }

    m_aliens = new Aliens(Vector2{50+OFFSET, 10+OFFSET});
  }

  virtual States Update() {
    if(m_gameOver) {
      return States::GAMEOVER;
    }
// Spaceship update & fire
    m_spaceship->Update();
    if(m_spaceship->isFiring()) {
      Vector2 laserPosition = Vector2{
        m_spaceship->getPosition().x + (m_spaceship->getDimension().x/2) - 1,
        m_spaceship->getPosition().y - LASER_HEIGHT
      };

      m_lasers.push_back(
        new Laser(laserPosition, Direction::UP)
      );

      m_spaceship->stopFiring();
    }
// Generate laser from random alien
    if(m_firingSpeed->eventTriggered()) {
      Vector2 alienPosition =  m_aliens->Firing();
      Vector2 laserPosition = Vector2{
        alienPosition.x + OFFSET + 20,
        alienPosition.y + OFFSET + 40
      };

      m_lasers.push_back(
        new Laser(laserPosition, Direction::DOWN)
      );
    }
// Fixed update
    if(m_speed->eventTriggered()) {
      m_spaceship->FixedUpdate();
      m_aliens->FixedUpdate();

// LASERS COLLISIONS
      for (int i = m_lasers.size()-1; i >= 0; --i) {
        m_lasers[i]->FixedUpdate();
// WITH WINDOWS
        if(m_lasers[i]->getPosition().y < OFFSET || 
          m_lasers[i]->getPosition().y > SCREEN_HEIGHT + OFFSET
        ) {
          delete m_lasers[i];
          m_lasers.erase(m_lasers.begin() + i);
          continue;
        }
// WITH ALIENS
        if(m_lasers[i]->getDirection() == UP && 
          m_aliens->CheckCollision(m_lasers[i]->getPosition())
        ) {
          delete m_lasers[i];
          m_lasers.erase(m_lasers.begin() + i);
          continue;
        }   
// WITH SPACESHIP
        if(m_lasers[i]->getPosition().x >= m_spaceship->getPosition().x &&
          m_lasers[i]->getPosition().x < m_spaceship->getPosition().x + m_spaceship->getDimension().x &&
          m_lasers[i]->getPosition().y >= m_spaceship->getPosition().y
        ) {
          m_gameOver = true;  
        }

// WITH OBSTACLES 
        for(auto obstacle : m_obstacles) {
          if(obstacle->DestroyCell(m_lasers[i]->getPosition())) {
            delete m_lasers[i];
            m_lasers.erase(m_lasers.begin() + i);
            break;
          }
        }
      }
    } // fixed update end

    return States::CONTINUE;
  }

  virtual void Draw() {
    m_spaceship->Draw();
    for(auto obstacle : m_obstacles) {
      obstacle->Draw();
    }

    m_aliens->Draw();
    for(auto laser : m_lasers) {
      laser->Draw();
    }
  }

  virtual ~GameState(){
    delete m_spaceship;
    delete m_speed;
    delete m_aliens;

    for(auto obstacle : m_obstacles) {
      delete obstacle;
    }
    
    for (auto laser : m_lasers) {
      delete laser;
    } 

    m_lasers.clear();
  }

};

