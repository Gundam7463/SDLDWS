#include "../../include/input/input_manager.h"



void InputManager::clearFrame() {
    m_keyboard.clearFrame();
	m_mouse.clearFrame();
	m_gamepad.clearFrame();
}
void InputManager::updateInput(SDL_Event &ev) {
    m_keyboard.updateInput(ev);
	m_mouse.updateInput(ev);
	m_gamepad.updateInput(ev);
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
bool InputManager::getMousePressed(int key) {
	return m_mouse.getPressed(key);
}
bool InputManager::getMouseReleased(int key) {
	return m_mouse.getReleased(key);
}
bool InputManager::getMouseHold(int key) {
	return m_mouse.getHolded(key);
}
void InputManager::getMousePosition(int *x, int *y) {
	m_mouse.getPosition(x, y);
}
bool InputManager::getJoyPressed(int joyID, Uint8 buttonID) {
	return m_gamepad.getJoyPressed(joyID, buttonID);
}
bool InputManager::getJoyReleased(int joyID, Uint8 buttonID) {
	return m_gamepad.getJoyReleased(joyID, buttonID);
}
bool InputManager::getJoyHold(int joyID, Uint8 buttonID) {
	return m_gamepad.getJoyHold(joyID, buttonID);
}
Sint16 InputManager::getJoyAxisMove(int joyID, Uint8 axis) {
	return m_gamepad.getAxisMove(joyID, axis);
}