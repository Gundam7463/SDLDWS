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
