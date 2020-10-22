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

/** The game class.
 * 
 * IS: the application main object, this object holds all information
 * about screen's, camera. This is an singleton class.
 * 
 * WHERE: on the main.cpp file.
 * 
 * HOW WORKS: simple initialize an run the application.
 */

#pragma once 

#include "camera.h"
#include "timer.h"
#include "../screen/screen_manager.h"
#include "../entity/object_factory.h"


class Game {
public:
	//Nothing for now.
    ~Game();
	
	//Singleton get method.
    static Game& instance() {
        static Game game;
        return game;
    }
    
    /** void run ( )
	 * 
	 * @brief set default values, do the game logic and finalize.
	 * 
	 */
    void run();
    
	//Get the object factory reference
	ObjectFactory& getFactory() { return m_objectFactory; }
	//Get the camera with the viewport reference
	Camera& getCamera() { return m_camera; }
	
private:
    Game();
    
    /** bool initialize ( )
	 * 
	 * @brief initialize default values.
	 * 
	 * @return true on success or false on errors.
	 */
    bool initialize();
	
    /** void finalize ( )
	 * 
	 * @brief unload everything.
	 */
    void finalize();
    
    /** void mainLoop ( )
	 * 
	 * @brief do the game logic and render.
	 */
    void mainLoop();
	
    /** void update ( int32_t elapsedTime )
	 * 
	 * @brief update the game logic.
	 * 
	 * @param elapsedTime the ms time delay in each iteration.
	 */
    void update(int32_t elapsedTime);
	
    /** void draw ( )
	 * 
	 * @brief render objects.
	 */
    void draw();
	
	/** void factoryRegister ( )
	 * 
	 * @brief register all possible object to be used on screens.
	 */
	void factoryRegister();
    
private:
    bool m_bRunning;//true = the game is running, false = go to finalize the game.
    Camera m_camera;
    Timer m_timer;//our timer to do the Frame logic, such get the elapsed time and fix the FPS.
	
	ScreenManager m_screenManager;//Handle our screen's.
	ObjectFactory m_objectFactory;//Holds object to be created.
};
