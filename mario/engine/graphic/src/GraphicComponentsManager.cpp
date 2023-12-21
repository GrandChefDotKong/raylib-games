#include "../GraphicComponentsManager.hpp"

void GraphicComponentsManager::render() {
  for(auto& component : m_components) {
    component.render();
  }
}