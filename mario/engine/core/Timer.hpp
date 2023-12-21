#pragma once
#include <raylib.h>

class Timer {
  private:
    double m_elapsedTime;
    double m_interval;

  public:
    Timer();
    Timer(double interval);
    void start();
    void setInterval(double interval);
    double getInterval();
    bool eventTriggered();
};