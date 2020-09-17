#pragma once 

#include <map>
#include <SDL2/SDL.h>


class Mouse {
public:
	Mouse();
    
	~Mouse();

	void createCursor(const char *path, int hot_x, int hot_y);
	
	void clearFrame();
    
	void updateInput(SDL_Event &ev);
	
	bool getPressed(int key);

	bool getReleased(int key);
    
	bool getHolded(int key);
	
	void getPosition(int *x, int *y);
	
private:
	std::map<int, bool> m_pressed;
	std::map<int, bool> m_released;
	std::map<int, bool> m_holded;
	
	SDL_Cursor *m_cursor;
    SDL_Surface *m_mouseSurface;
};
