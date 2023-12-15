#include "./includes/Alien.hpp"


Alien::Alien(Texture2D* texture, Texture2D* texture2, Vector2 position, Vector2 speed):
m_texture(texture), m_texture2(texture2), m_speed(speed)  {
  m_rectangle.x = position.x;
  m_rectangle.y = position.y;
  m_rectangle.width = 48;
  m_rectangle.height = 48;

  m_animationTree = new AnimationTree();

  Animation alive = Animation(*m_texture);
  alive.AddFrames((m_texture->width/16), Rectangle{0, 0, 16, 16}, 16);
  alive.setInterval(0.2);
  alive.setIsLoop(true);

  Animation dead = Animation(*m_texture2);
  dead.AddFrames(5, Rectangle{0, 0, 16, 16}, 16);
  dead.setInterval(0.2);
  dead.setIsLoop(false);

  m_animationTree->AddAnimation("alive", alive);
  m_animationTree->AddAnimation("dead", dead);
  m_animationTree->setCurrentAnimation("alive");
}

void Alien::Update() {
  m_animationTree->Update();

  if(!m_isAlive) {
    m_animationTree->setCurrentAnimation("dead");
  }
}

void Alien::FixedUpdate() {
  if(!m_isAlive) {
    return;
  }

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

const bool Alien::CheckCollision(Rectangle laser) {
  if(!m_isAlive) {
    return false;
  }

  if(CheckCollisionRecs(m_rectangle, laser)) {
    m_isAlive = false;
    return true;
  }

  return false;
}

const bool Alien::ShouldBeDeleted() {
  if(!m_isAlive && !m_animationTree->getCurrentAnimation().getIsPlaying()) {
    return true;
  }

  return false;
}

const Rectangle Alien::getPosition() {
  return m_rectangle;
}

const Direction Alien::getDirection() {
  return m_direction;
}

void Alien::ChangeDirection(Direction direction) {
  m_direction = direction;
}

void Alien::Draw() {
  m_animationTree->Draw(m_rectangle);
}

Alien::~Alien() {
  delete m_animationTree;
}


