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
 * IS: Timer limiter and counter for the application.
 * 
 * WHERE: Contained on game class.
 * 
 * HOW WORKS: 
 * 		1- FPS limiter. 
 * 		2- FPS counter.
 */

#pragma once 

#include "vector_2d.h"
#include <SDL2/SDL.h>



class Timer {
public:
	//Default sets
    Timer();
	
	/** void finalize ( )
	 * 
	 * @brief Get rid of the fps texture.
	 */
	void finalize();
    
    /** void updateFrames ( )
	* 
	* @brief Put on the top of the main loop to counter fps limit events.
	*/
    void updateFrames();
    
    /** void updateFramesCount ( )
	 * 
	 * @brief Put on the top of the fps limiter statement to count the FPS rate.
	 */
    void updateFramesCount();
    
    /** void setFps ( double fps )
	 * 
	 * @brief Set current fps rate to limit.
	 * 
	 * @param fps The fps value.
	 */
    void setFps(double fps);
    
    /** int32_t getElapsedTime ( ) 
	 * 
	 * @brief Get the current elapsedTime counted by updateFrames method.
	 * 
	 * @return The elapsed time value.
	 */
    int32_t getElapsedTime();
    
    /** double getFpsCount ( )
	 * 
	 * @brief Get the FPS rate value counted by updateFramesCount method.
	 * 
	 * @return The FPS rate value.
	 */
    double getFpsCount();
    
    /** bool getTimeEvent ( )
	 * 
	 * @brief Get true if the elapsed time counter reaches to your FPS value.
	 * 
	 * @return True if the event is reach.
	 */
    bool getTimeEvent();
    
    /** void drawFpsCount ( VectorInt2D position ) 
	 * 
	 * @brief Draw on the screen the FPS rate counted by updateFramesCount.
	 * 
	 * @param position The position to be draw on screen.
	 */
    void drawFpsCount(VectorInt2D position);
    
private:
    int32_t m_fpsCountPrevTime;//iteration previous ms value to fps counter 
    int32_t m_fpsCountFrameTime;//iteration fps count start ms

    int32_t m_elapsedTime;//iteration elapsed time ms
    float m_elapsedTimeCount;//iteration elapsed time ms counter
    
    int32_t m_currentTime;//iteration count start ms
    int32_t m_prevTime;//iteration previous ms value
    
    double m_fps;
    double m_fpsCount;//fps rate value
    int32_t m_fpsDelayToShow;//delay to render the fps value to a texture
    bool m_timeEvent;//fps limiter has reached
	
	SDL_Texture* m_fpsTexture;
	SDL_Rect m_fpsTextureRect;
};
