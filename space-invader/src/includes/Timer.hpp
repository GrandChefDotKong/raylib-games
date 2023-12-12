#pragma once
#include "params.hpp"

class Timer {
  private:
    double m_elapsedTime;
    double m_interval;

  public:
    Timer();
    Timer(double interval);
    void Start();
    void setInterval(double interval);
    double getInterval();
    bool eventTriggered();
};