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

#pragma once 

#include "camera.h"
#include "timer.h"
#include "../screen/screen_manager.h"
#include "../entity/object_factory.h"


class Game {
public:
    ~Game();
    static Game& instance() {
        static Game game;
        return game;
    }
    
    void run();
    
	ObjectFactory& getFactory() { return m_objectFactory; }
	Camera& getCamera() { return m_camera; }
	
private:
    Game();
    
    bool initialize();
    void finalize();
    
    void mainLoop();
    void update(int elapsedTime);
    void draw();
	
	void factoryRegister();
    
private:
    bool m_bRunning;
    Camera m_camera;
    Timer m_timer;
	
	ScreenManager m_screenManager;
	ObjectFactory m_objectFactory;
};
