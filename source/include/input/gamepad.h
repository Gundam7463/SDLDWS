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

/** The gamepad class.
 * 
 * IS: Input class for joysticks and gamepads.
 * 
 * WHERE: Contained only on InputManager class.
 * 
 * HOW WORKS: Simple call the methods on the InputManager class.
 * This object load and setup any connected gamepad on USB ports.
 * This object support multiple gamepads and check if has new gamepad connected in game.
 */

#pragma once 

#include <vector>
#include <map>
#include <SDL2/SDL.h>
#include <cstdint>



class Gamepad {
public:
	//run the setup
	Gamepad();
    
	//free allocated memory
	~Gamepad();
	
	/** void clearFrame ( )
	 * 
	 * @brief Clear current input frame.
	 */
	void clearFrame();
    
	/** void updateInput ( SDL_Event &ev )
	 * 
	 * @brief Update input frame and check for connected/disconnected devices.
	 * 
	 * @param ev The SDL_Event union on the main loop.
	 */
	void updateInput(SDL_Event &ev);
	
	/** bool getJoyPressed ( uint8_t joyID, uint8_t buttonID )
	 * 
	 * @brief Get the button pressed by gamepad id and button id.
	 * 
	 * @param joyID The joystick/gamepad id(0 for the first connected joy/pad).
	 * @param buttonID The joy/pad button id ( 0 .. n buttons ).
	 * 
	 * @return true on success or false if not.
	 */
	bool getJoyPressed(uint8_t joyID, uint8_t buttonID);

	/** bool getJoyReleased ( uint8_t joyID, uint8_t buttonID )
	 * 
	 * @brief Get the button released by gamepad id and button id.
	 * 
	 * @param joyID The joystick/gamepad id(0 for the first connected joy/pad).
	 * @param buttonID The joy/pad button id ( 0 .. n buttons ).
	 * 
	 * @return true on success or false if not.
	 */    
	bool getJoyReleased(uint8_t joyID, uint8_t buttonID);
    
	/** bool getJoyHold ( uint8_t joyID, uint8_t buttonID )
	 * 
	 * @brief Get the button holded by gamepad id and button id.
	 * 
	 * @param joyID The joystick/gamepad id(0 for the first connected joy/pad).
	 * @param buttonID The joy/pad button id ( 0 .. n buttons ).
	 * 
	 * @return true on success or false if not.
	 */
	bool getJoyHold(uint8_t joyID, uint8_t buttonID);
	
	/** int16_t getAxisMove ( uint8_t joyID, uint8_t axis )
	 * 
	 * @brief Get the axis value ( -32,768 to 32-767 )
	 * 
	 * @param joyID The joystick/gamepad id(0 for the first connected joy/pad).
	 * @param axis The axis ( 0 for the first axis .. n ).
	 * 
	 * @return The amount of motion.
	 */
	int16_t getAxisMove(uint8_t joyID, uint8_t axis);
	
private:

	//run the setup
	void initializeJoys();

	//free memory
	void finalizeJoys();

	std::vector<SDL_Joystick*> m_joysticks;
	std::vector<std::vector<bool>> m_joyButtonsPressed;
	std::vector<std::vector<bool>> m_joyButtonsReleased;
	std::vector<std::vector<bool>> m_joyButtonsHold;
	
	std::vector<std::vector<int32_t>> m_joyAxis; 
	
	bool m_bOnce;//used to check single press events.
};
