
#include "MenuState.cpp"

class Timer {
  private:
    double m_elapsedTime;
    double m_interval;

  public:
    Timer(double interval): m_interval(interval), m_elapsedTime(0) {}

    void Start() {
      m_elapsedTime = 0;
    }

    void setInterval(double interval) {
      m_interval = interval;
    }

    double getInterval() {
      return m_interval;
    }

    bool eventTriggered() {
      double currentTime = GetTime();
      
      if(currentTime - m_elapsedTime >= m_interval) { 
        m_elapsedTime = currentTime; 
        return true;
      }

      return false;
    }
};