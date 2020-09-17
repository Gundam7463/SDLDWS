#pragma once 

#include <map>
#include <SDL2/SDL.h>


class Keyboard {
public:
	Keyboard();
	~Keyboard();

	void clearFrame();
    
	void updateInput(SDL_Event &ev);

	bool getPressed(SDL_Scancode key);
    
	bool getReleased(SDL_Scancode key);
    
	bool getHold(SDL_Scancode key);

private:
	std::map<SDL_Scancode, bool> m_pressed;
	std::map<SDL_Scancode, bool> m_released;
	std::map<SDL_Scancode, bool> m_holded;
};
