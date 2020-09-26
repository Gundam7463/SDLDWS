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

#include "../../include/input/keyboard.h"


Keyboard::Keyboard() {}
Keyboard::~Keyboard() {}
void Keyboard::clearFrame() {
	m_pressed.clear();
	m_released.clear();
}
void Keyboard::updateInput(SDL_Event &ev) {
	if (ev.type == SDL_KEYDOWN)
	{
		if (ev.key.repeat == 0)
		{
			m_pressed[ev.key.keysym.scancode] = true;
		}
        m_released[ev.key.keysym.scancode] = false;
        m_holded[ev.key.keysym.scancode] = true;
	}
	else if (ev.type == SDL_KEYUP)
	{
		m_pressed[ev.key.keysym.scancode] = false;
		m_released[ev.key.keysym.scancode] = true;
		m_holded[ev.key.keysym.scancode] = false;
	}
}
bool Keyboard::getPressed(SDL_Scancode key) {
	return m_pressed[key];
}
bool Keyboard::getReleased(SDL_Scancode key) {
	return m_released[key];
}
bool Keyboard::getHold(SDL_Scancode key) {
	return m_holded[key];
}
