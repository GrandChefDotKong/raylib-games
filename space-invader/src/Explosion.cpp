#include "./includes/Explosion.hpp"

Explosion::Explosion(Texture2D* texture, Vector2 position):
m_texture(texture) {
  m_rectangle.x = position.x;
  m_rectangle.y = position.y;
  m_rectangle.width = 48;
  m_rectangle.height = 48;

  m_animation = Animation(*m_texture);
  m_animation.AddFrames(5, Rectangle{0, 0, 16, 16}, 16);
  m_animation.setInterval(0.2);
  m_animation.setIsLoop(true);
  m_animation.Start();
}

void Explosion::Update() {
  std::cout << "is playing : " << !m_animation.getIsPlaying() << std::endl;
  m_animation.Update();
}

void Explosion::Draw() {
  m_animation.Draw(m_rectangle);
}

Explosion::~Explosion() {}