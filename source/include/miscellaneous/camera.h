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

/** The camera class.
 * 
 * IS: screen motion for our entire game.
 * 
 * WHERE: Container only on game class, but visible to objects.
 * 
 * HOW WORKS: simple draw a portion of the render to the screen. 
 * Every time one screen is loaded the init method is called. 
 * On level loadLevel the max Width/Height is the level size.
 */

#pragma once 

#include <cstdint>
#include <SDL2/SDL_rect.h>
#include "vector_2d.h"


class Camera {
public:
	//Basic setups.
    Camera();
    
    /** void init ( )
	 * 
	 * @brief Set the viewport max size or reset
	 * 
	 * @param maxWidth the max width to the viewport
	 * @param maxHeight the max height to the viewport
	 */
    void init(uint32_t maxWidth, uint32_t maxHeight);
	
	//Move the camera along the x axis
	void moveHorizontal(float speed);
	//Move the camera along the y axis
	void moveVertical(float speed);

	SDL_Rect getViewportRect();
	VectorFloat2D getPosition() {
		return m_position;
	}

	//update the SDL/SDL_Renderer viewport
	void updateViewport();
	
private:
    VectorFloat2D m_position;
	VectorInt2D m_size;
};
