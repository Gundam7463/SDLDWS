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
        m_timer.updateFrames();
        
        InputManager::instance().clearFrame();
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
        
        if (m_timer.getTimeEvent())
        {
            m_timer.updateFramesCount();
            draw();
        }
    }
}
void Game::update(int elapsedTime) {
    Graphics::instance().setViewport(&m_camera.m_viewport);
	m_screenManager.update(elapsedTime);
}
void Game::draw() {
    Graphics::instance().clearColor();
    m_timer.drawFpsCount(VectorInt2D(0, 0));
	m_screenManager.draw();
    Graphics::instance().renderPresent();
}

void Game::factoryRegister() {
	m_objectFactory.registerObject("Background", new BackgroundFactoryContainer());
}
