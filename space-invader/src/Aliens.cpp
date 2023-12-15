#include "./includes/Aliens.hpp"

Aliens::Aliens(Vector2 position) {
  m_images.push_back(LoadImage("ressources/yellow_enemy.png"));
  m_images.push_back(LoadImage("ressources/green_enemy.png"));
  m_images.push_back(LoadImage("ressources/pink_enemy.png"));
  m_images.push_back(LoadImage("ressources/explosion.png"));

  m_speed.x = 2;
  m_speed.y = 12;

  for(auto image : m_images) {
    m_textures.push_back(LoadTextureFromImage(image));
  }

  this->Initiate(position);
}

void Aliens::Initiate(Vector2 position) {
  for(int i(0); i < m_cellSize; ++i) {

    Vector2 alienPosition;
    alienPosition.x = position.x + (i%ALIENS_COLUMNS) * m_cellSize;
    alienPosition.y = position.y + (i/ALIENS_COLUMNS) * m_cellSize;

    int index;

    i < ALIENS_COLUMNS ? index = 2 : i < ALIENS_COLUMNS*3 ? index = 1 : index = 0;

    m_aliens.push_back(
      new Alien(&m_textures[index], &m_textures[3], alienPosition, m_speed)
    );   
  }
}

const Vector2 Aliens::Firing() {
  int alienIndex =  GetRandomValue(0, m_aliens.size()-1);
  return Vector2{
    m_aliens[alienIndex]->getPosition().x, m_aliens[alienIndex]->getPosition().y
  };
}

bool Aliens::CheckCollision(const Rectangle laser) {
  for (int i = m_aliens.size()-1; i >= 0; --i) {
    if(m_aliens[i]->CheckCollision(laser)) {
      return true;
    }
  }

  return false;
}

void Aliens::Update() {
  for(int i(m_aliens.size()-1); i >= 0; --i) {
    m_aliens[i]->Update();
    if(m_aliens[i]->ShouldBeDeleted()) {
      delete m_aliens[i];
      m_aliens.erase(m_aliens.begin() + i);
    }
  }
}

void Aliens::FixedUpdate() {
  
  for(auto alien : m_aliens) {
    alien->FixedUpdate();
  }
  
  int leftAlien = SCREEN_WIDTH + OFFSET;
  int rightAlien = OFFSET;

  for(auto alien : m_aliens) {
    if(alien->getPosition().x < leftAlien) {
      leftAlien = alien->getPosition().x;
    }
    
    if(alien->getPosition().x + alien->getPosition().width > rightAlien) {
      rightAlien = alien->getPosition().x + alien->getPosition().width;
    }
  }

  if(m_aliens[0]->getDirection() == DOWN) {
    if(leftAlien <= OFFSET) {
      for(auto alien : m_aliens) {
        alien->ChangeDirection(RIGHT);
      }
      return;
    }

    for(auto alien : m_aliens) {
      alien->ChangeDirection(LEFT);
    } 

    return;
  }
  
  if(leftAlien <= OFFSET ||
    rightAlien >= SCREEN_WIDTH + OFFSET
  ) {
    for(auto alien : m_aliens) {
      alien->ChangeDirection(DOWN);
    } 
  }
}

void Aliens::Draw() {
  for(auto alien : m_aliens) {
    alien->Draw();
  }
}

Aliens::~Aliens() {
  for(auto alien : m_aliens) {
    delete alien;
  }

  for(auto image : m_images) {
    UnloadImage(image);
  }

  for(auto texture : m_textures) {
    UnloadTexture(texture);
  } 
}


