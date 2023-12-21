#pragma once
#include <string>
#include "GameObject.hpp"

class Component {
  protected:
    std::string m_id;
    GameObject* m_gameObject;

  public:
    Component(){}
    Component(std::string id, GameObject* gameObject) : m_id(id), m_gameObject(gameObject) {}

    void setId(std::string id) {
      m_id = id;
    }

    const std::string getId() const {
      return m_id;
    }

    const GameObject* getGameObject() const {
      return m_gameObject;
    }

    void setGameObject(GameObject* gameObject) {
      m_gameObject = gameObject;
    }


    virtual ~Component() = 0;
};

