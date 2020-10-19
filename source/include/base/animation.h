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


/** The animation class.
 * 
 * IS: Animation for our games.
 * 
 * WHERE: Contained on Sprite objects and Sprite Loader.
 * 
 * HOW WORKS: 
 * 		1- An container filled by Sprite Loader. 
 * 		2- Sprite loads an copy.
 */

#pragma once 

#include <SDL2/SDL_rect.h>
#include <cstdint>


class Sprite;

class Animation {
public:
	//Alternative setup
	Animation();
	//finalization
	~Animation();
	
	/** Animation ( uint16_t frameWidth, uint16_t frameHeight, uint8_t row, 
	 * 			uint8_t startColumn, uint8_t endColumn, int32_t frameDelay )
	 * 
	 * @brief Constructor setup.
	 * 
	 * @param frameWidth the horizontal frame width for each square.
	 * @param frameHeight the vertical frame height for each square.
	 * @param row the vertical line of this animation on the sprite sheet.
	 * @param startColumn the start horizontal column on the sprite sheet.
	 * @param endColumn the end square/frame.
	 * @param frameDelay the ms(milliseconds) delay between each frame.
	 */
    Animation(uint16_t frameWidth, uint16_t frameHeight, uint8_t row, 
	  			uint8_t startColumn, uint8_t endColumn, int32_t frameDelay);

	/** void setTarget ( Sprite* sprite )
	 * 
	 * @brief Select the target to this animation work on.
	 * 
	 * @param target one sprite object pointer.
	 */
    void setTarget(Sprite* target);
    
	/** void update ( int elapsedTime ) 
	 * 
	 * @brief do the logic.
	 * 
	 * @param elapsedTime the ms elapsed between each iteration of the game.
	 */
    void update(int32_t elapsedTime);
    
	//render
    void draw();
private:
    
    Sprite* m_pTarget;//target pointer reference.
    
    uint16_t m_frameWidth;
    uint16_t m_frameHeight;
    
    uint8_t m_row;
    uint8_t m_column;
    uint8_t m_startColumn;
    uint8_t m_endColumn;
    
    SDL_Rect m_src;//Represents the frame on the sprite sheet texture.
    
    int32_t m_frameDelay;
    int32_t m_frameDelayCount;//the frameDelay counter.
};
