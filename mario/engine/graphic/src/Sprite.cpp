#include "../Sprite.hpp"

Sprite::Sprite() {

}
  
Sprite::Sprite(std::string id, GameObject* gameObject) : GraphicComponent(id, gameObject) {}

const Vector2& Sprite::getPosition() const {
  return m_position;
}


const Texture2D* Sprite::getTexture() const {
  return m_texture;
}

const Color& Sprite::getColor() const {
  return m_color;
}

void Sprite::setPosition(const Vector2& position) {
  m_position = position;
}

void Sprite::setTexture(const Texture2D* texture) {
  m_texture = texture;
}

void Sprite::setColor(const Color& color) {
  m_color = color;
}

void Sprite::setScale(float scale) {
  m_scale = scale;
}

void Sprite::setRotation(float rotation) {
  m_rotation = rotation;
}

void Sprite::render() {
  DrawTextureEx(
    *m_texture,
    m_position,
    0,
    0,
    m_color
  ); 
}

Sprite::~Sprite() {}


