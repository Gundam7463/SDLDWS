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

#include "../../include/input/input_manager.h"



void InputManager::finalize() {
	delete m_gamepad;
	m_gamepad = 0;
}
void InputManager::clearFrame() {
    m_keyboard.clearFrame();
	m_mouse.clearFrame();
	m_gamepad->clearFrame();
}
void InputManager::updateInput(SDL_Event &ev) {
    m_keyboard.updateInput(ev);
	m_mouse.updateInput(ev);
	m_gamepad->updateInput(ev);
}
void InputManager::createCursor(const char *path, int hot_x, int hot_y) {
	m_mouse.createCursor(path, hot_x, hot_y);
}
bool InputManager::getKeyPressed(SDL_Scancode key) {
    return m_keyboard.getPressed(key);
}
bool InputManager::getKeyReleased(SDL_Scancode key) {
    return m_keyboard.getReleased(key);
}
bool InputManager::getKeyHold(SDL_Scancode key) {
    return m_keyboard.getHold(key);
}
bool InputManager::getMousePressed(uint8_t key) {
	return m_mouse.getPressed(key);
}
bool InputManager::getMouseReleased(uint8_t key) {
	return m_mouse.getReleased(key);
}
bool InputManager::getMouseHold(uint8_t key) {
	return m_mouse.getHolded(key);
}
void InputManager::getMousePosition(int *x, int *y) {
	m_mouse.getPosition(x, y);
}
bool InputManager::getJoyPressed(int joyID, uint8_t buttonID) {
	return m_gamepad->getJoyPressed(joyID, buttonID);
}
bool InputManager::getJoyReleased(int joyID, uint8_t buttonID) {
	return m_gamepad->getJoyReleased(joyID, buttonID);
}
bool InputManager::getJoyHold(int joyID, uint8_t buttonID) {
	return m_gamepad->getJoyHold(joyID, buttonID);
}
int16_t InputManager::getJoyAxisMove(int joyID, uint8_t axis) {
	return m_gamepad->getAxisMove(joyID, axis);
}

InputManager::InputManager() {
	m_gamepad = new Gamepad();
}