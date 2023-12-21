#pragma once
#include "../core/ComponentsManager.hpp"
#include "GraphicComponent.hpp"

class GraphicComponentsManager : public ComponentsManager<GraphicComponent> {
  public:
    GraphicComponentsManager() {}

    void render(); 

    ~GraphicComponentsManager() {}
};
