#pragma once 

#include <SDL2/SDL_rect.h>


class Camera {
public:
    Camera();
    
    void init();
    
public:
    SDL_Rect m_viewport;
    
private:
    
};
