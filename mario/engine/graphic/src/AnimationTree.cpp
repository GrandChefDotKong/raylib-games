#include "../AnimationTree.hpp"

AnimationTree::AnimationTree() {}

void AnimationTree::addAnimation(std::string animationName, Animation animation) {
  m_animations.insert({ animationName, animation });
}

const std::string AnimationTree::getCurrentAnimationName() {
  return m_currentAnimation;
}

const Animation AnimationTree::getCurrentAnimation() {
  return m_animations[m_currentAnimation];
}

void AnimationTree::setCurrentAnimation(std::string animationName) {
  if(m_currentAnimation == animationName) {
    return;
  }

  m_currentAnimation = animationName;
  m_animations[m_currentAnimation].init();  
}

void AnimationTree::update() { 
  m_animations[m_currentAnimation].update();
}

void AnimationTree::draw(const Rectangle destination) {
  m_animations[m_currentAnimation].draw(destination);
}

AnimationTree::~AnimationTree() {
  
}

