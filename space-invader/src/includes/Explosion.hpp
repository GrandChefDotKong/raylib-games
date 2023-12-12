#pragma once
#include "Animation.hpp"

class Explosion {
  private:
    Texture2D* m_texture;
    Animation m_animation;
    Rectangle m_rectangle;

  public:
    Explosion(Texture2D* texture, Vector2 position);
    void Update();
    void Draw();
    ~Explosion();
};