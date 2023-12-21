#include "../GameObject.hpp"

GameObject::GameObject() {

}

void GameObject::addComponents(std::string componentName, Component* component) {
  if(m_components.count(componentName) != 0) {
    std::cout << "Component name already used !" << std::endl;
    return;
  }

  m_components[componentName] = component;
  component->setGameObject(this);
}

void GameObject::removeComponent(std::string componentName) {
  m_components.erase(componentName);
}

const Component* GameObject::getComponent(std::string componentName) const {
  return m_components.at(componentName);
}

GameObject::~GameObject() {
  
}