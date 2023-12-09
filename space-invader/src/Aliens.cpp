#include "Timer.cpp"

class Alien {

private:
  Texture2D* m_texture;
  Vector2 m_position;
  Direction m_direction = RIGHT;
  int m_offset;
  float m_scale = 1;
  int m_speedX;
  int m_speedY;
  int m_width = 55;
  int m_height = 55;

  bool m_isFiring = false;
  bool m_isAlive = true;

public:
  Alien(Texture2D* texture, Vector2 position, int offset, int speedX, int speedY):
  m_texture(texture), m_position(position), m_speedX(speedX), m_speedY(speedY), m_offset(offset)  {
      
  }

  void FixedUpdate() {
    switch (m_direction) {
      case IDDLE:
        break;
      case LEFT:
        m_position.x -= m_speedX;
      break;
      case RIGHT:
        m_position.x += m_speedX;
      break;
      case DOWN:
        m_position.y += m_speedY;
      break;
    }
  }

  bool CheckCollision(Vector2 laserPosition) {
    if(laserPosition.x + 3 >= m_position.x && laserPosition.x < m_position.x + m_width &&
      laserPosition.y <= m_position.y + m_height && laserPosition.y > m_position.y
    ) {
      m_isAlive = false;
      return true;
    }

    return false;
  }

  const Vector2 getPosition() {
    return m_position;
  }

  void changeDirection(Direction direction) {
    m_direction = direction;
  }

  void Draw() {
    DrawTextureEx(
      *m_texture,
      Vector2{m_position.x + m_offset, m_position.y + m_offset},
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

  Vector2 m_position;
  Direction m_direction = RIGHT;

  int m_cellSize = 55;
  int m_offset = 30;
  int m_speedX = 1;
  int m_speedY = 2;

public:
  Aliens(Vector2 position): m_position(position) {
    m_images.push_back(LoadImage("ressources/alien_1.png"));
    m_images.push_back(LoadImage("ressources/alien_2.png"));
    m_images.push_back(LoadImage("ressources/alien_3.png"));


    for(auto image : m_images) {
      m_textures.push_back(LoadTextureFromImage(image));
    }

    this->Initiate();
  }

  void Initiate() {
    for(int i(0); i < m_cellSize; ++i) {

      Vector2 alienPosition;
      alienPosition.x = m_position.x + (i%11) * m_cellSize;
      alienPosition.y = m_position.y + (i/11) * m_cellSize;

      int index;

      i < 11 ? index = 2 : i < 33 ? index = 1 : index = 0;

      m_aliens.push_back(
        new Alien(&m_textures[index], alienPosition, m_offset, m_speedX, m_speedY)
      );   
    }
  }

  const Vector2 Firing() {
    int alienIndex =  GetRandomValue(0, m_cellSize-1);
    return m_aliens[alienIndex]->getPosition();
  }

  bool CheckCollision(const Vector2 laserPosition) {
    for (int i = m_aliens.size()-1; i >= 0; --i) {
      if(m_aliens[i]->CheckCollision(laserPosition)) {
        delete m_aliens[i];
        m_aliens.erase(m_aliens.begin() + i);
        return true;
      }
    }

    return false;
  }

  void FixedUpdate() {    

    if(m_direction == DOWN) {
      m_position.x <= 0 ? m_direction = RIGHT : m_direction = LEFT;
    } else if(m_position.x + 600 > SCREEN_WIDTH || m_position.x <= 0) {
      m_direction = DOWN;
    }

    switch (m_direction) {
      case IDDLE:
        break;
      case LEFT:
        m_position.x -= m_speedX;
      break;
      case RIGHT:
        m_position.x += m_speedX;
      break;
      case DOWN:
        m_position.y += m_speedY;
      break;
    }

    for(auto alien : m_aliens) {
      alien->changeDirection(m_direction);
      alien->FixedUpdate();
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

