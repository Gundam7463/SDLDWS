#include <string>
#include <SDL2/SDL.h>
#include "../../include/base/timer.h"
#include "../../include/base/graphics.h"
#include "../../include/input/input_manager.h"



Timer::Timer() {
    m_startTime = 0;
    m_frameTime = 0;
    
    m_currentTime = 0;
    m_prevTime = 0;
    m_elapsedTimeCount = 0.f;
    m_elapsedTime = 0;
    m_timeEvent = false;
    m_fps = 60.0;
    m_fpsCount = 0.0;
    m_prevFpsCount = 0.0;
    
    m_fpsDelayToShow = 0;
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
    m_frameTime = SDL_GetTicks() - m_startTime;
    m_startTime = SDL_GetTicks();
    
    m_fpsCount = (m_frameTime > 0) ? 1000.f / m_frameTime : 0.f;
}

void Timer::setFps(double fps) {
    m_fps = fps;
}
double Timer::getFpsCount() {
    return m_fpsCount;
}
int Timer::getElapsedTime() {
    return m_elapsedTime;
}

bool Timer::getTimeEvent() {
    return m_timeEvent;
}

void Timer::drawFpsCount(VectorInt2D position) {
    if (m_fpsDelayToShow >= 2000)
    {
        m_fpsDelayToShow = 0;
        m_prevFpsCount = m_fpsCount;
    }
    
    std::string str = "FPS:  ";
    str += std::to_string(m_prevFpsCount);
    str.resize(10);
    
    SDL_Color color = { 216, 30, 120, 0xff };
    Graphics::instance().drawTextSolid("barlow16", str.c_str(), color, 0, position);   
}
