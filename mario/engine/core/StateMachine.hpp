#pragma once
#include "State.hpp"

template<class T>
class StateMachine  {
  private:
    T* m_currentState;

  public:
    StateMachine() {}

    virtual void init() = 0;
    virtual void update() = 0;

    const T* getCurrentState() const {
      return m_currentState
    }

    void setCurrentState(T* newState) {
      m_currentState = newState;
    }

    virtual ~StateMachine() {}
};

