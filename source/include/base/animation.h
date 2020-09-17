#pragma once 

#include <SDL2/SDL_rect.h>


class Sprite;

class Animation {
public:
	Animation();
    Animation(int frameWidth, int frameHeight, int row, int startColumn,
	int endColumn, int frameDelay);

    void setTarget(Sprite* target);
    
    void update(int elapsedTime);
    
    void draw();
private:
    
    Sprite *m_pTarget;
    
    int m_frameWidth;
    int m_frameHeight;
    
    int m_row;
    int m_column;
    int m_startColumn;
    int m_endColumn;
    
    SDL_Rect m_src;
    
    int m_frameDelay;
    int m_frameDelayCount;
};
