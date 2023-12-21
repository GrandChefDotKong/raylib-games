#include "../Animation.hpp"

Animation::Animation() {}

Animation::Animation(const Texture2D& texture): m_texture(&texture) {
}

Animation::Animation(const Animation& animation): 
  m_texture(animation.m_texture), m_frames(animation.m_frames), m_timer(animation.m_timer),
  m_color(animation.m_color), m_isLoop(animation.m_isLoop),m_isPlaying(animation.m_isPlaying)
{}

void Animation::setIsLoop(bool isLoop) {
  m_isLoop = isLoop;
}

void Animation::setInterval(float interval) {
  m_timer.setInterval(interval);
}

void Animation::setTexture(const Texture2D& texture) {
  m_texture = &texture;
}

const bool Animation::getIsPlaying() const {
  return m_isPlaying;
}

const Texture2D* Animation::getTexture() {
  return m_texture;
}

const Rectangle Animation::getCurrentFrame() {
  return m_frames.at(m_currentFrame);
}

const int Animation::getIndex() {
  return m_currentFrame;
}

const int Animation::getNumberFrames() {
  return m_frames.size();
}

void Animation::stop() {
  m_isPlaying = false;
}

void Animation::addFrame(Rectangle frame) {
  m_frames.push_back(frame);
}

void Animation::addFrames(
  unsigned int numberOfFrames, Rectangle firstFrame, 
  unsigned int incrementX, unsigned int incrementY
) {

  for(int i(0); i < numberOfFrames; ++i) {
    this->addFrame(Rectangle{
      firstFrame.x + i * incrementX, firstFrame.y + i * incrementY, 
      firstFrame.width, firstFrame.height
    });
  }
}

void Animation::init() {
  m_isPlaying = true;
  m_currentFrame = 0;
  m_timer.start();
}

void Animation::update() {
  if(!m_isPlaying) {
    return;
  }

  if(!m_timer.eventTriggered()) {
    return;
  }

  if(m_currentFrame+1 >= m_frames.size()) {
    if(!m_isLoop) {
      this->stop();
      return;
    }

    m_currentFrame = 0;
  } else { 
    m_currentFrame++;
  }
}

void Animation::draw(const Rectangle destination) {
  if(!m_isPlaying) {
    return;
  }
  DrawTexturePro(
    *m_texture,
    m_frames[m_currentFrame],
    destination,
    Vector2{0, 0},
    0,
    WHITE
  );
}

Animation::~Animation() {

}


