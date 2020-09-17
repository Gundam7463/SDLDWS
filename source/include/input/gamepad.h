#pragma once 

#include <vector>
#include <map>
#include <SDL2/SDL.h>



class Gamepad {
public:
	Gamepad();
    
	~Gamepad();
	
	void clearFrame();
    
	void updateInput(SDL_Event &ev);
	
	bool getJoyPressed(int joyID, Uint8 buttonID);
    
	bool getJoyReleased(int joyID, Uint8 buttonID);
    
	bool getJoyHold(int joyID, Uint8 buttonID);
	
	Sint16 getAxisMove(int joyID, Uint8 axis);
	
private:

	void initializeJoys();

	void finalizeJoys();

	std::vector<SDL_Joystick*> m_joysticks;
	std::vector<std::vector<bool>> m_joyButtonsPressed;
	std::vector<std::vector<bool>> m_joyButtonsReleased;
	std::vector<std::vector<bool>> m_joyButtonsHold;
	
	std::vector<std::vector<Sint16>> m_joyAxis; 
	
	bool m_bOnce;
};
