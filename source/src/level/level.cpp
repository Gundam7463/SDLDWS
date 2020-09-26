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