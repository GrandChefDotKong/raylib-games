#include "MenuState.cpp"

class GameState: public State {

private:
  unsigned int m_score;
  Timer* m_speed;
  bool m_gameOver;

  Spaceship* m_spaceship;
  Obstacle* m_obstacle;
  std::vector<Laser*> m_lasers;

public:
  GameState(): m_score(0), m_gameOver(false) {
    m_spaceship = new Spaceship("ressources/spaceship.png");
    m_speed = new Timer(0.01);
    m_obstacle = new Obstacle(299, obstacle_grid, Vector2{200, 200}, RED);
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

    if(m_speed->eventTriggered()) {
      m_spaceship->FixedUpdate();

      for (int i = m_lasers.size()-1; i >= 0; --i) {
        m_lasers[i]->FixedUpdate();
        if(m_obstacle->DestroyCell(m_lasers[i]->getPosition())) {
          delete m_lasers[i];
          m_lasers.erase(m_lasers.begin() + i);
        }
      }

      this->DeleteLasers();
    }

    return States::CONTINUE;
  }

  void DeleteLasers() {
    for (int i = m_lasers.size()-1; i >= 0; --i) {
      if(m_lasers[i]->getPosition().y < 0 ) {
        delete m_lasers[i];
        m_lasers.erase(m_lasers.begin() + i);
      }
    } 
  }


  virtual void Draw() {
    m_spaceship->Draw();
    m_obstacle->Draw();
    for (auto laser : m_lasers) {
      laser->Draw();
    }
  }

  virtual ~GameState(){
    delete m_spaceship;
    delete m_speed;
    delete m_obstacle;
    for (auto laser : m_lasers) {
      delete laser;
    } 

    m_lasers.clear();
  }

};

