#pragma once 

#include <string>
#include <SDL2/SDL_rect.h>
#include "../base/vector_2d.h"
#include "../loader/loader.h"


class Entity {
public:
	virtual ~Entity() { }

    virtual bool load(const Loader* loader) = 0;
    virtual void unload() = 0;
    
    virtual void update(int elapsedTime) { }
    virtual void draw() { }
    
protected:

    VectorFloat2D m_position;
    VectorInt2D m_size;
};
