#include "Timer.cpp"

class Alien {

private:
  Texture2D* m_texture;
  Rectangle m_rectangle;
  Direction m_direction = RIGHT;

  int m_offset;
  float m_scale = 1;

  Vector2 m_speed;

  bool m_isFiring = false;
  bool m_isAlive = true;

public:
  Alien(Texture2D* texture, Vector2 position, Vector2 speed, int offset):
  m_texture(texture), m_speed(speed), m_offset(offset)  {
    m_rectangle.x = position.x;
    m_rectangle.y = position.y;
    m_rectangle.width = m_texture->width;
    m_rectangle.height = m_texture->height;
      
  }

  void FixedUpdate() {
    switch (m_direction) {
      case IDDLE:
        break;
      case LEFT:
        m_rectangle.x -= m_speed.x;
      break;
      case RIGHT:
        m_rectangle.x += m_speed.x;
      break;
      case DOWN:
        m_rectangle.y += m_speed.y;
      break;
    }
  }

  bool CheckCollision(Rectangle laser) {
    if(laser.x + laser.width >= m_rectangle.x && 
      laser.x < m_rectangle.x + m_rectangle.width &&
      laser.y <= m_rectangle.y + m_rectangle.height && 
      laser.y > m_rectangle.y
    ) {
      m_isAlive = false;
      return true;
    }

    return false;
  }

  const Rectangle getPosition() {
    return m_rectangle;
  }

  const Direction getDirection() {
    return m_direction;
  }

  void ChangeDirection(Direction direction) {
    m_direction = direction;
  }

  void Draw() {
    DrawTextureEx(
      *m_texture,
      Vector2{m_rectangle.x + m_offset, m_rectangle.y + m_offset},
      0,
      m_scale,
      WHITE
    );
  }

  ~Alien() {}
};


class Aliens {

private:
  std::vector<Alien*> m_aliens;
  std::vector<Texture2D> m_textures;
  std::vector<Image> m_images;
  Direction m_direction = RIGHT;

  Vector2 m_speed;

  int m_cellSize = ALIENS_CELL_SIZE;
  int m_offset = OFFSET;

public:
  Aliens(Vector2 position) {
    m_images.push_back(LoadImage("ressources/alien_1.png"));
    m_images.push_back(LoadImage("ressources/alien_2.png"));
    m_images.push_back(LoadImage("ressources/alien_3.png"));

    m_speed.x = 2;
    m_speed.y = 12;

    for(auto image : m_images) {
      m_textures.push_back(LoadTextureFromImage(image));
    }

    this->Initiate(position);
  }

  void Initiate(Vector2 position) {
    for(int i(0); i < m_cellSize; ++i) {

      Vector2 alienPosition;
      alienPosition.x = position.x + (i%ALIENS_COLUMNS) * m_cellSize;
      alienPosition.y = position.y + (i/ALIENS_COLUMNS) * m_cellSize;

      int index;

      i < ALIENS_COLUMNS ? index = 2 : i < ALIENS_COLUMNS*3 ? index = 1 : index = 0;

      m_aliens.push_back(
        new Alien(&m_textures[index], alienPosition, m_speed, m_offset)
      );   
    }
  }

  const Vector2 Firing() {
    int alienIndex =  GetRandomValue(0, m_cellSize-1);
    return Vector2{
      m_aliens[alienIndex]->getPosition().x, m_aliens[alienIndex]->getPosition().y
    };
  }

  bool CheckCollision(const Rectangle laser) {
    for (int i = m_aliens.size()-1; i >= 0; --i) {
      if(m_aliens[i]->CheckCollision(laser)) {
        delete m_aliens[i];
        m_aliens.erase(m_aliens.begin() + i);
        return true;
      }
    }

    return false;
  }

  void FixedUpdate() {
    
    for(auto alien : m_aliens) {
      alien->FixedUpdate();
    }

    if(m_aliens[0]->getDirection() == DOWN) {
      if(m_aliens[0]->getPosition().x <= OFFSET) {
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

    if(m_aliens[0]->getPosition().x <= 0 ||
      m_aliens[ALIENS_COLUMNS-1]->getPosition().x + 
      m_aliens[ALIENS_COLUMNS-1]->getPosition().width >= SCREEN_WIDTH
    ) {
      for(auto alien : m_aliens) {
        alien->ChangeDirection(DOWN);
      } 
    }

    
  }

  void Draw() {
    for(auto alien : m_aliens) {
      alien->Draw();
    }
  }

  ~Aliens() {
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
};

