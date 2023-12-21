#pragma once
#include "../core/Component.hpp"

class GraphicComponent : public Component {
  
  public:
    GraphicComponent() {}
    GraphicComponent(std::string id, GameObject* gameObject) : Component(id, gameObject) {}

    virtual void render() = 0;

    ~GraphicComponent() {}
};


