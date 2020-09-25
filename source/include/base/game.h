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
