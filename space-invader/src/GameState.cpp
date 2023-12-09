#include "MenuState.cpp"

class GameState: public State {

private:
  unsigned int m_score;
  Timer* m_speed;
  Timer* m_firingSpeed;
  bool m_gameOver;

  Spaceship* m_spaceship;
  std::vector<Laser*> m_lasers;
  std::vector<Obstacle*> m_obstacles;
  Aliens* m_aliens;

public:
  GameState(): m_score(0), m_gameOver(false) {
    m_spaceship = new Spaceship("ressources/spaceship.png");
    m_speed = new Timer(0.02);
    m_firingSpeed = new Timer(0.1);
    m_obstacles.push_back(new Obstacle(299, obstacle_grid, Vector2{200, 620}, RED));
    m_obstacles.push_back(new Obstacle(299, obstacle_grid, Vector2{350, 620}, RED));
    m_obstacles.push_back(new Obstacle(299, obstacle_grid, Vector2{500, 620}, RED));
    m_aliens = new Aliens(Vector2{50+OFFSET, 30+OFFSET});
  }

  virtual States Update() {
    if(m_gameOver) {
      return States::GAMEOVER;
    }

    m_spaceship->Update();

    if(m_spaceship->isFiring()) {

      Vector2 laserPosition = Vector2{
        m_spaceship->getPosition().x + (m_spaceship->getDimension().x/2) - 1,
        m_spaceship->getPosition().y - 15
      };

      m_lasers.push_back(
        new Laser(laserPosition, Direction::UP)
      );

      m_spaceship->stopFiring();
    }

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
    }

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

