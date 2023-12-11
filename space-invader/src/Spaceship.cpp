#include "./includes/Spaceship.hpp"


  Spaceship::Spaceship(std::string path, int speed): 
  m_speed(speed), m_isFiring(false), m_isAlive(true) {

    m_image = LoadImage(path.c_str());
    m_texture = LoadTextureFromImage(this->m_image);

    m_rectangle = Rectangle{
      SCREEN_WIDTH/2-(float)m_texture.width/2, 
      SCREEN_HEIGHT, 
      (float)m_texture.width, 
      (float)m_texture.height
    };
  }
  
  void Spaceship::Update() {

    if(IsKeyUp(KEY_SPACE)) {
      m_isFiring = false;
    }

    if(IsKeyUp(KEY_LEFT) && IsKeyUp(KEY_RIGHT)) {
      m_direction = IDDLE;
    }

    if(IsKeyDown(KEY_LEFT)) {
      m_direction = LEFT;
    }

    if(IsKeyDown(KEY_RIGHT)) {
      m_direction = RIGHT;
    }

    if(IsKeyPressed(KEY_SPACE)) {
      m_isFiring = true;
    }
  }

  void Spaceship::FixedUpdate() {
    switch (m_direction) {
      case IDDLE:
        break;
      case LEFT:
        m_rectangle.x <= OFFSET ? 
          m_rectangle.x = OFFSET : m_rectangle.x -= m_speed;
      break;
      case RIGHT:
        m_rectangle.x >= SCREEN_WIDTH + OFFSET ? 
          m_rectangle.x = SCREEN_WIDTH + OFFSET : m_rectangle.x += m_speed;
      break;
    }
  }

  const bool Spaceship::isFiring() {
    return m_isFiring;
  }

  void Spaceship::stopFiring() {
    m_isFiring = false;
  }
  
  const Rectangle Spaceship::getPosition() {
    return m_rectangle;
  }

  Spaceship::~Spaceship() {
    UnloadImage(m_image);
    UnloadTexture(m_texture);
  }

  void Spaceship::Draw() {
    DrawTextureEx(
      m_texture,
      Vector2{m_rectangle.x, m_rectangle.y},
      0,
      1,
      WHITE
    );
  }








