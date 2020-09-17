#pragma once 

#include <string>
#include <map>
#include <SDL2/SDL.h>
#include "entity.h"

class Animation;


class Sprite : public Entity {
public:
    friend class Animation;
    
    virtual bool load(const Loader* loader);
    virtual void unload();
    
    virtual void update(int elapsedTime);
    virtual void draw();
    
protected:
    std::string m_textureName;
    std::map<std::string, Animation*> m_animations;
    std::map<std::string, Animation*>::iterator m_animationsIt;
    std::string m_currentAnimation;
};
