#pragma once
#include "Timer.hpp"
#include "State.hpp"

class Animation {  
 private:
  std::vector<Rectangle> m_frames;
  const Texture2D* m_texture;
  Timer m_timer;
  Color m_color = WHITE;

  int m_currentFrame = 0;
  bool m_isLoop = true;
  bool m_isPlaying = true;

 public:
  Animation();
  Animation(const Texture2D& texture);
  Animation(const Animation& animation);
  // Setters
  void setIsLoop(bool isLoop);
  void setInterval(float interval);
  void setTexture(const Texture2D& texture);
  // Getterss
  bool getIsPlaying();
  const Texture2D* getTexture();
  const Rectangle getCurrentFrame();
  const int getIndex();
  const int getNumberFrames();
  // Methods
  void Start();
  void Stop();
  void AddFrame(Rectangle frame);
  void AddFrames(
    unsigned int numberOfFrames, Rectangle firstFrame, 
    unsigned int incrementX, unsigned int incrementY = 0
  );
  //Virtual Methods
  virtual void Update();
  virtual void Draw(const Rectangle destination);

  ~Animation();
};
