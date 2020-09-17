#pragma once 

#include <string>
#include <map>
#include "screen.h"
#include "../base/tinyxml2.h"



class ScreenManager {
public:
	ScreenManager();

	void unload();

	bool loadScreenFiles();
	
	bool empty() { return m_empty; }
	
	void setScreen(const std::string& name);
	
	void popScreen(const std::string& name);
	
	void update(int elapsedTime);
	void draw();
	
private:
	std::map<std::string, Screen*> m_screens;
	std::map<std::string, Screen*>::iterator m_screensIt;
	std::map<std::string, tinyxml2::XMLDocument*> m_screensFiles;
	std::map<std::string, tinyxml2::XMLDocument*>::iterator m_screensFilesIt;
	
	std::string m_currentScreen;
	bool m_empty;
	
	bool loadScreen(const std::string& name);
};
