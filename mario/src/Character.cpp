#include "./includes/Character.hpp"


Character::Character(Texture2D* texture, Vector2 position, Vector2 speed):
m_texture(texture), m_speed(speed)  {
  m_rectangle.x = position.x;
  m_rectangle.y = position.y;
  m_rectangle.width = 48;
  m_rectangle.height = 48;

  m_animationTree = new AnimationTree();

  Animation alive = Animation(*m_texture);
  alive.AddFrames((m_texture->width/16), Rectangle{0, 0, 16, 16}, 16);
  alive.setInterval(0.2);
  alive.setIsLoop(true);


  m_animationTree->AddAnimation("alive", alive);
  m_animationTree->setCurrentAnimation("alive");
}

void Character::Update() {
  m_animationTree->Update();

  if(!m_isAlive) {
    m_animationTree->setCurrentAnimation("dead");
  }
}

void Character::FixedUpdate() {
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

const Rectangle Character::getPosition() {
  return m_rectangle;
}

const Direction Character::getDirection() {
  return m_direction;
}


void Character::Draw() {
  m_animationTree->Draw(m_rectangle);
}

Character::~Character() {
  delete m_animationTree;
}


