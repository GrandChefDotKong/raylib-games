#include "./includes/AnimationTree.hpp"

AnimationTree::AnimationTree() {}

void AnimationTree::AddAnimation(std::string animationName, Animation animation) {
  m_animations.insert({ animationName, animation });
}

const std::string AnimationTree::getCurrentAnimation() {
  return m_currentAnimation;
}

void AnimationTree::setCurrentAnimation(std::string animationName) {
  if(m_currentAnimation == animationName) {
    return;
  }

  m_currentAnimation = animationName;
  m_animations[m_currentAnimation].Start();  
}

void AnimationTree::Update() { 
  m_animations[m_currentAnimation].Update();
}

void AnimationTree::Draw(const Rectangle destination) {
  m_animations[m_currentAnimation].Draw(destination);
}

AnimationTree::~AnimationTree() {
  
}

