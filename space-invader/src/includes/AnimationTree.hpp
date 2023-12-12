#pragma once
#include "params.hpp"
#include "Animation.hpp"

class AnimationTree {  
  protected:
    std::map<std::string, Animation> m_animations;
    std::string m_currentAnimation;

  public:
    AnimationTree();

    void AddAnimation(std::string animationName, 
      Animation animation
    );

    const std::string getCurrentAnimation();
    void setCurrentAnimation(std::string animationName);
    
    virtual void Update();
    virtual void Draw(const Rectangle destination);

    ~AnimationTree();
};
