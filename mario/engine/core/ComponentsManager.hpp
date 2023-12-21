#pragma once
#include <vector>
#include <string>
#include "Component.hpp"

template <class T>
class ComponentsManager {
  protected:
    std::vector<T> m_components;

  public:
    ComponentsManager(){}

    template <class T>
    void addComponent(T& component) {
      m_components.push_back(component);
    }
    
    template <class T>
    void removeComponent(T& component) {
      m_components.push_back(component);
    }

    template <class T>
    const T& getComponent(std::string componentId) const {
      return m_components.at(componentId)
    }

    template <class T>
    void update() {
      for (auto& component: m_components) {
        component.update();
      }
    }

    virtual ~ComponentsManager() = 0;
};
