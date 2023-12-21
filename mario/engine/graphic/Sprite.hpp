#pragma once
#include "./GraphicComponent.hpp"
#include <raylib.h>

class Sprite : public GraphicComponent {
private:
  const Texture2D* m_texture;
  Color m_color = WHITE;
  Vector2 m_position;
  float m_scale = 1;
  float m_rotation = 0;

public:
  Sprite();
  Sprite(std::string id, GameObject* gameObject);

  const Vector2& getPosition() const;
  const Texture2D* getTexture() const;
  const Color& getColor() const;
  void setPosition(const Vector2& position);
  void setTexture(const Texture2D* texture);
  void setColor(const Color& color);
  void setScale(float scale);
  void setRotation(float rotation);

  virtual void render();

  ~Sprite();
};

