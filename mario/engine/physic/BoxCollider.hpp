#pragma once
#include "../core/Component.hpp"
#include <raylib.h>
#include <raymath.h>
#include <string>

class BoxCollider: public Component {
  private:
    Rectangle m_box;
  
  public:
    BoxCollider() {}
    BoxCollider(std::string id, GameObject* gameObject) : Component(id, gameObject) {}

    const Rectangle getCollider() {
      return m_box;
    }

    void setCollider(Rectangle& box) {
      m_box = box;
    }
};
