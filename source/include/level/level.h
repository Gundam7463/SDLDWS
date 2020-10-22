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

#pragma once 

#include <string>
#include <vector>
#include <map>
#include "../miscellaneous/tinyxml2.h"
#include "tile_layer.h"
#include "entity_layer.h"
#include "tileset.h"


struct LevelInfo {
	std::string m_level_name;
	
	uint32_t m_level_width_in_tile;
	uint32_t m_level_height_in_tile;
	uint8_t m_level_tile_width_px;
	uint8_t m_level_tile_height_px;
	std::vector<Tileset*> m_tilesets;
	
	void print() {
		SDL_Log("\n\nLevelInfo: \n");
		SDL_Log("level-name: %s\n", m_level_name.c_str());
		SDL_Log("level-width-in-tile: %d\n", m_level_width_in_tile);
		SDL_Log("level-height-in-tile: %d\n", m_level_height_in_tile);
		SDL_Log("level-tile-width-px: %d\n", m_level_tile_width_px);
		SDL_Log("level-tile-height-px: %d\n", m_level_tile_height_px);
		SDL_Log("level-num-tilesets: %ld\n", m_tilesets.size());
	}
};



class Level {
public:
    bool loadLevelFiles();
    void unload();
	
	bool loadLevel(const std::string& levelName);
	
    void update(int32_t elapsedTime);
    void draw();
	
private:
	std::vector<TileLayer*> m_tileLayers;
	std::vector<EntityLayer*> m_spriteLayers;
	
	std::map<std::string, tinyxml2::XMLDocument*> m_levelFiles;
	std::map<std::string, tinyxml2::XMLDocument*>::iterator m_levelFilesIt;
	
	LevelInfo m_levelInfo;
};