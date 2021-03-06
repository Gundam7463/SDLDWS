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

#include <map>
#include <SDL2/SDL.h>


class Mouse {
public:
	Mouse();
    
	~Mouse();

	void createCursor(const char *path, int hot_x, int hot_y);
	
	void clearFrame();
    
	void updateInput(SDL_Event &ev);
	
	bool getPressed(uint8_t key);

	bool getReleased(uint8_t key);
    
	bool getHolded(uint8_t key);
	
	void getPosition(int *x, int *y);
	
private:
	std::map<uint8_t, bool> m_pressed;
	std::map<uint8_t, bool> m_released;
	std::map<uint8_t, bool> m_holded;
	
	SDL_Cursor *m_cursor;
    SDL_Surface *m_mouseSurface;
};
