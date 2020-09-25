#include "../../include/level/level.h"

extern std::string gRootDir;


bool Level::loadLevelFiles(const Loader* loader) {
	
	std::string path = gRootDir;
	path += "/level/list-levels.xml";
	
	tinyxml2::XMLDocument doc;
	doc.LoadFile(path.c_str());
	if (doc.Error())
	{
		doc.PrintError();
		return false;
	}
	
	tinyxml2::XMLElement* pRoot = doc.FirstChildElement();
	
	for (tinyxml2::XMLElement* e = pRoot->FirstChildElement(); e; e = e->NextSiblingElement())
	{
		std::string levelName = e->Attribute("name");
		std::string levelPath = gRootDir;
		levelPath += "/level/";
		levelPath += e->Attribute("path");
		
		tinyxml2::XMLDocument* pDoc = new tinyxml2::XMLDocument();
		pDoc->LoadFile(levelPath.c_str());
		if (pDoc->Error())
		{
			pDoc->PrintError();
			
			unload();
			return false;
		}
		
		m_levelFiles[levelName] = pDoc;
	}
	
	return true;
}
void Level::unload() {
	for (unsigned int i = 0; i < m_layers.size(); i++)
	{
		m_layers[i]->unload();
		delete m_layers[i];
	}
	m_layers.clear();
	
	for (m_levelFilesIt = m_levelFiles.begin(); m_levelFilesIt != m_levelFiles.end();
	m_levelFilesIt++)
	{
		delete m_levelFilesIt->second;
	}
	m_levelFiles.clear();
}
void Level::update(int elapsedTime) {
	for (unsigned int i = 0; i < m_layers.size(); i++)
	{
		m_layers[i]->update(elapsedTime);
	}
}
void Level::draw() {
	for (unsigned int i = 0; i < m_layers.size(); i++)
	{
		m_layers[i]->draw();
	}
}