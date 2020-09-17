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
