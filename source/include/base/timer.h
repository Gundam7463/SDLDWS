#pragma once 

#include "vector_2d.h"



class Timer {
public:
    Timer();
    
    void updateFrames();
    
    void updateFramesCount();
    
    void setFps(double fps);
    
    int getElapsedTime();
    
    double getFpsCount();
    
    bool getTimeEvent();
    
    void drawFpsCount(VectorInt2D position);
    
private:
    int m_startTime;
    int m_frameTime;

    int m_elapsedTime;
    float m_elapsedTimeCount;
    
    int m_currentTime;
    int m_prevTime;
    
    double m_fps;
    double m_fpsCount;
    double m_prevFpsCount;
    int m_fpsDelayToShow;
    bool m_timeEvent;
};
