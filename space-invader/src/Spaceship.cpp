#include "./includes/Spaceship.hpp"


  Spaceship::Spaceship(std::string path, int speed): 
  m_speed(speed), m_isFiring(false), m_isAlive(true) {

    Image image = LoadImage(path.c_str());
    m_texture = LoadTextureFromImage(image);

    UnloadImage(image);
    
    m_animationTree = new AnimationTree();

    Animation iddle = Animation(m_texture);
    iddle.AddFrame(Rectangle{16, 0, 16, 16});
    iddle.setInterval(0.2);
    iddle.setIsLoop(true);

    Animation left = Animation(m_texture);
    left.AddFrame(Rectangle{0, 0, 16, 16});
    left.setInterval(0.2);
    left.setIsLoop(true);
    
    Animation right = Animation(m_texture);
    right.AddFrame(Rectangle{32, 0, 16, 16});
    right.setInterval(0.2);
    right.setIsLoop(true);

    m_animationTree->AddAnimation("iddle", iddle);
    m_animationTree->AddAnimation("left", left);
    m_animationTree->AddAnimation("right", right);
    m_animationTree->setCurrentAnimation("iddle");

    m_rectangle = Rectangle{
      SCREEN_WIDTH/2-(float)m_texture.width/2, 
      SCREEN_HEIGHT - 24, 
      48, 
      48    
    };
  }
  
  void Spaceship::Update() {

    if(IsKeyUp(KEY_SPACE)) {
      m_isFiring = false;
    }

    if(IsKeyUp(KEY_LEFT) && IsKeyUp(KEY_RIGHT)) {
      m_direction = IDDLE;
      m_animationTree->setCurrentAnimation("iddle");
    }

    if(IsKeyDown(KEY_LEFT)) {
      m_direction = LEFT;
      m_animationTree->setCurrentAnimation("left");
    }

    if(IsKeyDown(KEY_RIGHT)) {
      m_direction = RIGHT;
      m_animationTree->setCurrentAnimation("right");
    }

    if(IsKeyPressed(KEY_SPACE)) {
      m_isFiring = true;
    }

    m_animationTree->Update();
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
  
  void Spaceship::Draw() {
    m_animationTree->Draw(m_rectangle);
  }

  Spaceship::~Spaceship() {
    delete m_animationTree;
    UnloadTexture(m_texture);
  }

 








