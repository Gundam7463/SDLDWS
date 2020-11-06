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
#include "../../include/level/level.h"
#include "../../include/level/entity_layer.h"
#include "../../include/miscellaneous/game.h"

extern std::string gRootDir;


bool Level::loadLevelFiles() {
	
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
	for (uint32_t i = 0; i < m_tileLayers.size(); i++)
	{
		m_tileLayers[i]->unload();
		delete m_tileLayers[i];
	}
	m_tileLayers.clear();
	
	for (uint32_t i = 0; i < m_spriteLayers.size(); i++)
	{
		m_spriteLayers[i]->unload();
		delete m_spriteLayers[i];
	}
	m_spriteLayers.clear();
	
	for (uint32_t i = 0; i < m_levelInfo.m_tilesets.size(); i++)
	{
		delete m_levelInfo.m_tilesets[i];
	}
	m_levelInfo.m_tilesets.clear();
	
	
	for (m_levelFilesIt = m_levelFiles.begin(); m_levelFilesIt != m_levelFiles.end();
	m_levelFilesIt++)
	{
		delete m_levelFilesIt->second;
	}
	m_levelFiles.clear();
}
bool Level::loadLevel(const std::string& levelName) {
	
	m_levelFilesIt = m_levelFiles.find(levelName);
	if (m_levelFilesIt != m_levelFiles.end())
	{
		tinyxml2::XMLElement* root = m_levelFilesIt->second->FirstChildElement();
		SDL_Log("\nLoading Level Info...\n");
		
		if (std::string(root->Value()) == "map")
		{
			m_levelInfo.m_level_name = levelName;
			
			m_levelInfo.m_level_width_in_tile = root->IntAttribute("width");
			m_levelInfo.m_level_height_in_tile = root->IntAttribute("height");
			m_levelInfo.m_level_tile_width_px = root->IntAttribute("tilewidth");
			m_levelInfo.m_level_tile_height_px = root->IntAttribute("tileheight");
			
			SDL_Log("Level Info successfull loaded.\n");
			SDL_Log("\nLoading Level sprite's layer's...\n");
			
			for (tinyxml2::XMLElement* objectgroup = root->FirstChildElement(); objectgroup; 
					objectgroup = objectgroup->NextSiblingElement())
			{
				if (std::string(objectgroup->Value()) == "objectgroup")
				{
					EntityLayer *newEntityLayer = new EntityLayer();
					if (!newEntityLayer->load(objectgroup))
					{
						delete newEntityLayer;
						unload();
						return false;
					}
					
					m_spriteLayers.push_back(newEntityLayer);
				}
			}
			
			SDL_Log("Level sprite's layer's successfull loaded.\n");
			SDL_Log("\nLoading Level tile's layer's...\n");
			
			for (tinyxml2::XMLElement* map = root->FirstChildElement(); map;
				map = map->NextSiblingElement())
			{
				if (std::string(map->Value()) == "tileset")
				{
					Tileset* newTileset = new Tileset(
						map->IntAttribute("firstgid"),
						map->Attribute("name"),
						map->IntAttribute("tilewidth"),
						map->IntAttribute("tileheight"),
						map->IntAttribute("tilecount"),
						std::string(map->FirstChildElement()->Attribute("source")).erase(0, 7)
					);
					
					m_levelInfo.m_tilesets.push_back(newTileset);
				}
				else if (std::string(map->Value()) == "layer")
				{
					TileLayer* newTileLayer = new TileLayer();
					if (!newTileLayer->load(map, m_levelInfo))
					{
						unload();
						return false;
					}
					m_tileLayers.push_back(newTileLayer);
				}
			}
			
			SDL_Log("Level tile's layer's successfull loaded.\n");
		}
	}
	else {
		SDL_Log("Error on loading level: %s\n", levelName.c_str());
		unload();
		return false;
	}
	
	Game::instance().getCamera().init(m_levelInfo.m_level_width_in_tile * m_levelInfo.m_level_tile_width_px,
		m_levelInfo.m_level_height_in_tile * m_levelInfo.m_level_tile_height_px);
	
	return true;
}
void Level::update(int32_t elapsedTime) {
	for (uint32_t i = 0; i < m_tileLayers.size(); i++)
	{
		m_tileLayers[i]->update(elapsedTime);
	}
	
	for (uint32_t i = 0; i < m_spriteLayers.size(); i++)
	{
		m_spriteLayers[i]->update(elapsedTime);
	}
}
void Level::draw() {
	for (uint32_t i = 0; i < m_tileLayers.size(); i++)
	{
		m_tileLayers[i]->draw(m_levelInfo);
	}
	
	for (uint32_t i = 0; i < m_spriteLayers.size(); i++)
	{
		m_spriteLayers[i]->draw();
	}
}