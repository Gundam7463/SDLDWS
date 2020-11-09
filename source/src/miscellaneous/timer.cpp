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

#include <sstream>
#include <SDL2/SDL.h>
#include "../../include/miscellaneous/timer.h"
#include "../../include/miscellaneous/graphics.h"
#include "../../include/input/input_manager.h"



Timer::Timer() {
    m_fpsCountPrevTime = 0;
    m_fpsCountFrameTime = 0;
    
    m_currentTime = 0;
    m_prevTime = 0;
    m_elapsedTimeCount = 0.f;
    m_elapsedTime = 0;
    m_timeEvent = false;
    m_fps = 60.0;
    m_fpsCount = 0.0;
    
    m_fpsDelayToShow = 0;
	m_fpsTexture = nullptr;
}

void Timer::finalize() {
	if (m_fpsTexture)
	{
		SDL_DestroyTexture(m_fpsTexture);
		m_fpsTexture = nullptr;
	}
}
void Timer::updateFrames() {
    m_currentTime = SDL_GetTicks();
    m_elapsedTime = m_currentTime - m_prevTime;
    m_prevTime = m_currentTime;
    
    m_elapsedTimeCount += m_elapsedTime / 1000.f;
    m_fpsDelayToShow += m_elapsedTime;
    
    if (m_elapsedTimeCount >= 1.0 / m_fps)
    {
        m_elapsedTimeCount = 0;
        m_timeEvent = true;
    }
    else {
        m_timeEvent = false;
    }
}
void Timer::updateFramesCount() {
    m_fpsCountFrameTime = SDL_GetTicks() - m_fpsCountPrevTime;
    m_fpsCountPrevTime = SDL_GetTicks();
    
    m_fpsCount = (m_fpsCountFrameTime > 0) ? 1000.f / m_fpsCountFrameTime : 0.f;
}

void Timer::setFps(double fps) {
    m_fps = fps;
}
double Timer::getFpsCount() {
    return m_fpsCount;
}
int32_t Timer::getElapsedTime() {
    return m_elapsedTime;
}

bool Timer::getTimeEvent() {
    return m_timeEvent;
}

void Timer::drawFpsCount(VectorFloat2D position) {
    if (m_fpsDelayToShow >= 2000)
    {
		m_fpsDelayToShow = 0;
		
		if (m_fpsTexture)
		{
			SDL_DestroyTexture(m_fpsTexture);
			m_fpsTexture = nullptr;
		}

		
		std::stringstream strText;
		strText << "FPS:  " << m_fpsCount;


		SDL_Color color = { 230, 230, 230, 0xff };
		m_fpsTexture = Graphics::instance().drawTextSolidToTexture("barlow20", strText.str().c_str(),
			color, &m_fpsTextureRect); 
    }

	if (m_fpsTexture)
	{
		const SDL_Rect dstRect = { int(position.getX()), int(position.getY()), m_fpsTextureRect.w,
			m_fpsTextureRect.h };
		
		Graphics::instance().drawTexture(m_fpsTexture, 0, &dstRect);
	}
}
