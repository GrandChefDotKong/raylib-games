#pragma once
#include "StateMachine.hpp"

template <class T>
class State {
  protected:
    T* m_stateMachine;

  public:
    State(){}

    virtual void init() = 0;
    virtual void update() = 0;

    template <class t>
    const T* getStateMachine() const {
      return m_stateMachine;
    }

    template <class T>
    void setStateMachine(T* machine) {
      m_stateMachine = machine
    }

    virtual ~State(){}
};