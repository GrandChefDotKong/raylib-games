#pragma once
#include "Animation.hpp"
#include "../core/StateMachine.hpp"
#include <string>
#include <map>

class AnimationTree : StateMachine<Animation>  {  
  protected:
    std::map<std::string, Animation> m_animations;
    std::string m_currentAnimation;

  public:
    AnimationTree();

    void addAnimation(std::string animationName, 
      Animation animation
    );

    const std::string getCurrentAnimationName();
    const Animation getCurrentAnimation();
    void setCurrentAnimation(std::string animationName);
    
    virtual void init();
    virtual void update();
    virtual void draw(const Rectangle destination);

    ~AnimationTree();
};
