#pragma once
#include "../core/Timer.hpp"
#include "../core/State.hpp"
#include <raylib.h>
#include <raymath.h>
#include <vector>
#include "./AnimationTree.hpp"
#include "GraphicComponent.hpp"

class Animation : public State<AnimationTree>, public GraphicComponent {  
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
  // Getters
  const bool getIsPlaying() const;
  const Texture2D* getTexture();
  const Rectangle getCurrentFrame();
  const int getIndex();
  const int getNumberFrames();
  // Methods
  void stop();
  void addFrame(Rectangle frame);
  void addFrames(
    unsigned int numberOfFrames, Rectangle firstFrame, 
    unsigned int incrementX, unsigned int incrementY = 0
  );
  //Virtual Methods
  virtual void init();
  virtual void update();
  virtual void draw(const Rectangle destination);

  ~Animation();
};
