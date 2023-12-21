#pragma once
#include "Component.hpp"
#include <string>
#include <iostream>
#include <map>

class GameObject {
  private:
    std::string m_id;
    std::map<std::string, Component*> m_components;  

  public:
    GameObject() {}

    void addComponents(std::string componentName, Component* component) {
      if(m_components.count(componentName) != 0) {
        std::cout << "Component name already used !" << std::endl;
        return;
      }

      m_components[componentName] = component;
      component->setGameObject(this);
    }

    void removeComponent(std::string componentName) {
      m_components.erase(componentName);
    }

    const Component* getComponent(std::string componentName) const {
      return m_components.at(componentName);
    }

    ~GameObject() {}
};
