#include "./includes/Timer.hpp"

Timer::Timer() {}

Timer::Timer(double interval): m_interval(interval) {}

void Timer::Start() {
  m_elapsedTime = 0;
}

void Timer::setInterval(double interval) {
  m_interval = interval;
}

double Timer::getInterval() {
  return m_interval;
}

bool Timer::eventTriggered() {
  double currentTime = GetTime();
  
  if(currentTime - m_elapsedTime >= m_interval) { 
    m_elapsedTime = currentTime; 
    return true;
  }

  return false;
}

