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

#include "keyboard.h"
#include "mouse.h"
#include "gamepad.h"


class InputManager {
public:
    static InputManager& instance() {
       static InputManager _instance;
       return _instance;
    }
    
    void clearFrame();
    
    void updateInput(SDL_Event &ev);
	
	void createCursor(const char *path, int hot_x, int hot_y);

	bool getMousePressed(int key);
	bool getMouseReleased(int key);
	bool getMouseHold(int key);
	void getMousePosition(int *x, int *y);
    
    bool getKeyPressed(SDL_Scancode key);
    bool getKeyReleased(SDL_Scancode key);
    bool getKeyHold(SDL_Scancode key);
	
	bool getJoyPressed(int joyID, Uint8 buttonID);
	bool getJoyReleased(int joyID, Uint8 buttonID);
	bool getJoyHold(int joyID, Uint8 buttonID);
	
	Sint16 getJoyAxisMove(int joyID, Uint8 axis);
    
private:
    InputManager() {}

    Keyboard m_keyboard;
	Mouse m_mouse;
	Gamepad m_gamepad;
};
