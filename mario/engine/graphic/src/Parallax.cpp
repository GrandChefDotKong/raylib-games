#include "../Parallax.hpp"

Parallax::Parallax() {}

void Parallax::AddBackground(std::string name, Vector2 scrollingSpeed, const Texture2D* texture) {
  Background background;
  background.name = name;
  background.position = Vector2{OFFSET, OFFSET};
  background.scrollingSpeed = scrollingSpeed;
  background.texture = texture;

  m_backgrounds.push_back(background);
}

void Parallax::Update() {

}

void Parallax::FixedUpdate() {
  for(auto& background : m_backgrounds) {
    background.position.x <= -background.texture->width*5.85 ? 
      background.position.x = 0 :
      background.position.x -= background.scrollingSpeed.x;
    background.position.y >= background.texture->height*5.85 ?
      background.position.y = 0 :
      background.position.y += background.scrollingSpeed.y;
  }
}

void Parallax::Draw() {
  for(auto background : m_backgrounds) {
    DrawTextureEx(*background.texture, background.position, 0.0f, 5.85, WHITE);
    DrawTextureEx(
      *background.texture, 
      Vector2{background.position.x, background.position.y-128*5.85f}, 
      0.0f, 
      5.85, 
      WHITE);
  }
}

Parallax::~Parallax() {}


