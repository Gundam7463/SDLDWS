/*
	 MIT License

	Copyright (c) 2020 Danrley Awesley Rodrigues Machado

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.
*/

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
