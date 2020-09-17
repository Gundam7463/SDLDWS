#include <SDL2/SDL.h>
#include "../../include/screen/screen_manager.h"

extern std::string gRootDir;


ScreenManager::ScreenManager() {
	m_currentScreen = "NONE"; 
	m_empty = true;
}
void ScreenManager::unload() {
	for (m_screensIt = m_screens.begin(); m_screensIt != m_screens.end(); m_screensIt++)
	{
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
	path += "/screen/screens.xml";
	
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
		SDL_Log("Error can't find screen: %s\n", name.c_str());
	}
	else {
	
		m_screensIt = m_screens.find(name);
		if (m_screensIt != m_screens.end())
		{
			m_currentScreen = name;
			SDL_Log("Current screen: %s\n", name.c_str());
		}
		else if (!loadScreen(name))
		{
			SDL_Log("Error on load screen: %s\n", name.c_str());
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

void ScreenManager::update(int elapsedTime) {
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

bool ScreenManager::loadScreen(const std::string& name) {
	
	m_screens[name] = new Screen();
	tinyxml2::XMLElement *element = m_screensFiles[name]->FirstChildElement();
	if (!(m_screens[name]->load(element)))
	{
		SDL_Log("Cannot parser screen!\n");
		return false;
	}
	
	m_currentScreen = name;
	
	m_empty = false;
	return true;
}
