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
#include "../../include/screen/screen_manager.h"
#include "../../include/screen/splash_screen.h"
#include "../../include/screen/play_screen.h"
#include "../../include/screen/main_menu_screen.h"
#include "../../include/screen/settings_screen.h"
#include "../../include/screen/pause_screen.h"

extern std::string gRootDir;


ScreenManager::ScreenManager() {
	m_currentScreen = "NONE"; 
	m_empty = true;
}
void ScreenManager::unload() {
	for (m_screensIt = m_screens.begin(); m_screensIt != m_screens.end(); m_screensIt++)
	{
		m_screensIt->second->unload();
		delete m_screensIt->second;
	}
	m_screens.clear();
	
	for (m_screensFilesIt = m_screensFiles.begin(); m_screensFilesIt != m_screensFiles.end();
	m_screensFilesIt++)
	{
		delete m_screensFilesIt->second;
	}
	m_screensFiles.clear();
	
	m_empty = true;
}

bool ScreenManager::loadScreenFiles() {

	std::string path = gRootDir;
	path += "/screen/list-screens.xml";
	
	tinyxml2::XMLDocument doc;
	doc.LoadFile(path.c_str());
	if (doc.Error())
	{
		doc.PrintError();
		return false;
	}
	
	tinyxml2::XMLElement *pRoot = doc.FirstChildElement();
	
	for (tinyxml2::XMLElement *e = pRoot->FirstChildElement(); e; e = e->NextSiblingElement())
	{
		std::string screenName = e->Attribute("name");
		std::string screenPath = gRootDir;
		screenPath += "/screen/";
		screenPath += e->Attribute("path");
		
		tinyxml2::XMLDocument *pDoc = new tinyxml2::XMLDocument();
		pDoc->LoadFile(screenPath.c_str());
		if (pDoc->Error())
		{
			pDoc->PrintError();
			
			unload();
			return false;
		}
		
		m_screensFiles[screenName] = pDoc;
	}
	
	return true;
}

void ScreenManager::setScreen(const std::string& name) {
	m_screensFilesIt = m_screensFiles.find(name);
	
	if (m_screensFilesIt == m_screensFiles.end())
	{
		SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, "ScreenManager: can't find screen %s, try rename it in the list-screens.xml to SplashScreen, MainMenuScreen, PlayScreen\n", name.c_str());
	}
	else {
	
		m_screensIt = m_screens.find(name);
		if (m_screensIt != m_screens.end())
		{
			m_currentScreen = name;
			SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Current screen: %s\n", name.c_str());
		}
		else 
		{
			if (!loadScreen(name))
			{
				SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, "Error on load screen: %s\n", name.c_str());
			}
		}
	}
}
void ScreenManager::popScreen(const std::string& name) {
	m_screensIt = m_screens.find(name);
	if (m_screensIt != m_screens.end())
	{
		m_screens[name]->unload();
		delete m_screens[name];
		
		m_screens.erase(m_screensIt);
	}
	
	if (m_screens.size() > 0)
	{
		m_currentScreen = m_screens.begin()->first;
	}
	else {
		m_empty = true;
	}
}

void ScreenManager::update(int32_t elapsedTime) {
	if (!m_empty)
	{
		m_screens[m_currentScreen]->update(elapsedTime);
	}
}
void ScreenManager::draw() {
	if (!m_empty)
	{
		m_screens[m_currentScreen]->draw();
	}
}

static Screen* getScreen(const std::string& name) {
	Screen* screen = nullptr;
	
	if (name == "SplashScreen")
	{
		screen = new SplashScreen();
	}
	else if (name == "MainMenuScreen")
	{
		screen = new MainMenuScreen();
	}
	else if (name == "PlayScreen")
	{
		screen = new PlayScreen();
	}
	else if (name == "SettingsScreen")
	{
		screen = new SettingsScreen();
	}
	else if (name == "PauseScreen")
	{
		screen = new PauseScreen();
	}
	else {
		SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, "Screen: screen name invalid, try rename it on your source code set screen to: SplashScreen, MainMenuScreen, PlayScreen");
	}
	
	return screen;
}
bool ScreenManager::loadScreen(const std::string& name) {
	
	Screen *screen = getScreen(name);
	
	if (screen)
	{
		m_screens[name] = screen;
		
		tinyxml2::XMLElement *element = m_screensFiles[name]->FirstChildElement();
		if (!(m_screens[name]->load(element)))
		{
			SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, "Cannot parser screen!\n");
			return false;
		}
		
		m_currentScreen = name;
		
		m_empty = false;
		
		return true;
	}
	
	return false;
}
