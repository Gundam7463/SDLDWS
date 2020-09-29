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

#include <SDL2/SDL.h>
#include "../../include/base/game.h"
#include "../../include/base/graphics.h"
#include "../../include/input/input_manager.h"
#include "../../include/entity/background.h"


Game::~Game() {
}
void Game::run() {
    m_bRunning = true;
    
    if (initialize())
    {
        mainLoop();    
        
        finalize();
    }
}
Game::Game() : m_bRunning(false) {
}
bool Game::initialize() {
    Graphics::instance().loadFont("Barlow-Light.ttf", "barlow16", 16);
	
    m_camera.init();
    InputManager::instance().createCursor("cursor.png", 0, 0);
	
	
	factoryRegister();
	
	
	if (!m_screenManager.loadScreenFiles())
	{
		SDL_Log("Cannot read list-screens.xml file\n");
		return false;
	}
	m_screenManager.setScreen("PlayScreen");

    return true;
}
void Game::finalize() {
	m_screenManager.unload();
    Graphics::instance().unload();
}
void Game::mainLoop() {
    SDL_Event event;
		
    while(m_bRunning)
    {   
        m_timer.updateFrames();//update frame on the main loop.
        InputManager::instance().clearFrame();//clear all input frame, after and before.
		
        while(SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
            {
                m_bRunning = false;
				return ;
            }
            InputManager::instance().updateInput(event);
        }

		if (m_screenManager.empty())
		{
			m_bRunning = false;
			return ;
		}
		
        update(m_timer.getElapsedTime());
        
		//Draw only on an FPS fixed value's.
        if (m_timer.getTimeEvent())
        {
            m_timer.updateFramesCount();
            draw();
        }
    }
}
void Game::update(int elapsedTime) {
	//Update the SDL viewport
    Graphics::instance().setViewport(&m_camera.m_viewport);
	m_screenManager.update(elapsedTime);
}
void Game::draw() {
    Graphics::instance().clearColor();
	m_screenManager.draw();
	m_timer.drawFpsCount(VectorInt2D(0, 0));
    Graphics::instance().renderPresent();
}

void Game::factoryRegister() {
	m_objectFactory.registerObject("Background", new BackgroundFactoryContainer());
}
