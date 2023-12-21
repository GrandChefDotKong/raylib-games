#include "./includes/GameState.hpp"

GameState::GameState(): m_score(0), m_gameOver(false) {

  this->LoadingAssets();

  AssetsManager* assetManager = AssetsManager::getInstance();

  m_parallax.AddBackground("middle_ground", Vector2{0, 1.2}, assetManager->getAsset("middle_ground"));
  m_parallax.AddBackground("for_ground", Vector2{0, 1.8}, assetManager->getAsset("for_ground"));
  m_parallax.AddBackground("back_ground", Vector2{0, 0.8}, assetManager->getAsset("back_ground"));

  m_spaceship = new Spaceship("ressources/ship.png");

  m_speed = new Timer(0.02);
  m_firingSpeed = new Timer(0.1);

  for(int i(1); i <= NUMBER_OBSTACLE; ++i) {
    m_obstacles.push_back(
      new Obstacle(
        ROWS*COLUMNS, 
        obstacle_grid, 
        Vector2{(float)i*100+50, 620}, 
        CELL_SIZE, 
        ROWS, 
        COLUMNS, 
        GREEN
      )
    );
  }

  m_aliens = new Aliens(Vector2{50+OFFSET, 10+OFFSET});
}

void GameState::LoadingAssets() {
  AssetsManager* assetManager = AssetsManager::getInstance();

  Texture2D forGround = LoadTexture("ressources/close_stars.png"); 
  Texture2D middleGround = LoadTexture("ressources/space.png");
  Texture2D backGround = LoadTexture("ressources/far_stars.png");

  assetManager->addAsset("for_ground", forGround);
  assetManager->addAsset("middle_ground", middleGround);
  assetManager->addAsset("back_ground", backGround);
}

States GameState::Update() {
  if(m_gameOver) {
    return States::GAMEOVER;
  }

// Spaceship update & fire
  m_spaceship->Update();
  if(m_spaceship->isFiring()) {
    Vector2 laserPosition = Vector2{
      m_spaceship->getPosition().x + (m_spaceship->getPosition().width/2) - 1,
      m_spaceship->getPosition().y - LASER_HEIGHT
    };

    m_lasers.push_back(
      new Laser(laserPosition, Direction::UP, BLUE)
    );

    m_spaceship->stopFiring();
  }
// Aliens update
  m_aliens->Update();
// Generate laser from random alien
  if(m_firingSpeed->eventTriggered()) {
    this->GenerateLaser();
  }
// Fixed update
  if(m_speed->eventTriggered()) {
    this->FixedUpdate();
  }

  return States::CONTINUE;
}

void GameState::FixedUpdate() {
  m_parallax.FixedUpdate();

  m_spaceship->FixedUpdate();
  m_aliens->FixedUpdate();

  for (int i = m_lasers.size()-1; i >= 0; --i) {
    m_lasers[i]->FixedUpdate();

    if(this->HandleCollision(m_lasers[i])) {
      delete m_lasers[i];
      m_lasers.erase(m_lasers.begin()+i);
    }
  }
}

void GameState::GenerateLaser() {
  Vector2 alienPosition =  m_aliens->Firing();
  Vector2 laserPosition = Vector2{
    alienPosition.x + OFFSET + 20,
    alienPosition.y + OFFSET + 40
  };

  m_lasers.push_back(new Laser(laserPosition, Direction::DOWN, RED));
}

bool GameState::HandleCollision(Laser* laser) {
// WITH WINDOWS
  if(laser->getPosition().y < OFFSET || 
    laser->getPosition().y > SCREEN_HEIGHT + OFFSET
  ) {  
    return true;
  }
// WITH ALIENS
  if(laser->getDirection() == UP && 
  m_aliens->CheckCollision(laser->getPosition())) {
    m_score += 10;
    return true;
  }   
// WITH SPACESHIP
  if(CheckCollisionRecs(m_spaceship->getPosition(), laser->getPosition())) {
    m_gameOver = true;  
  }

// WITH OBSTACLES 
  for(auto obstacle : m_obstacles) {
    if(obstacle->DestroyCell(laser->getPosition())) {
      return true;
    }
  }

  return false;
}

void GameState::Draw() {
  m_parallax.Draw();
  m_spaceship->Draw();

  for(auto obstacle : m_obstacles) {
    obstacle->Draw();
  }

  m_aliens->Draw();
  for(auto laser : m_lasers) {
    laser->Draw();
  }
  
  DrawText(TextFormat("Score : %i", m_score), OFFSET+10, OFFSET+10, 20, WHITE);
}

GameState::~GameState(){
  delete m_spaceship;
  delete m_aliens;
  delete m_firingSpeed;
  delete m_speed;
  
  for(auto obstacle : m_obstacles) {
    delete obstacle;
  }
  
  for (auto laser : m_lasers) {
    delete laser;
  } 
}


