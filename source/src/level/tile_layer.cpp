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

#include "../../include/level/tile_layer.h"
#include "../../include/level/level.h"
#include "../../include/miscellaneous/game.h"
#include "../../include/input/input_manager.h"


bool TileLayer::load(tinyxml2::XMLElement* layer, const LevelInfo& levelInfo) {
	
	tinyxml2::XMLElement* data = layer->FirstChildElement();
	for (tinyxml2::XMLNode* node = data->FirstChild(); node; node = node->NextSibling())
	{
		//Get global tile ids from <data> tag.
		tinyxml2::XMLText* text = node->ToText();
		//Setup the gids from this tile layer.
		setGids(text->Value());
		//printGids(levelInfo);
	}
	setTiles(levelInfo);
	
	return true;
}
void TileLayer::unload() {
	for (uint32_t i = 0; i < m_tiles.size(); i++)
	{
		delete m_tiles[i];
	}
	m_tiles.clear();
}

void TileLayer::update(int32_t elapsedTime) {
	
	if (InputManager::instance().getKeyHold(SDL_SCANCODE_LEFT))
	{
		Game::instance().getCamera().moveHorizontal(0.13f * elapsedTime);
	}
	if (InputManager::instance().getKeyHold(SDL_SCANCODE_RIGHT))
	{
		Game::instance().getCamera().moveHorizontal((-0.13f) * elapsedTime);
	}
	if (InputManager::instance().getKeyHold(SDL_SCANCODE_DOWN))
	{
		Game::instance().getCamera().moveVertical((-0.13f) * elapsedTime);
	}
	if (InputManager::instance().getKeyHold(SDL_SCANCODE_UP))
	{
		Game::instance().getCamera().moveVertical(0.13f * elapsedTime);
	}
}
void TileLayer::draw(const LevelInfo& levelInfo) {
	int ww, wh;
	Graphics::instance().getWindowSize(&ww, &wh);
	ww += levelInfo.m_level_tile_width_px;
	wh += levelInfo.m_level_tile_height_px;
	
	VectorFloat2D camPos = Game::instance().getCamera().getPosition();

	const uint32_t startRowInput = camPos.getY() / levelInfo.m_level_tile_height_px < 0 ? -(camPos.getY() / levelInfo.m_level_tile_height_px) : camPos.getY() / levelInfo.m_level_tile_height_px;
	const uint32_t startColumnInput = camPos.getX() / levelInfo.m_level_tile_width_px < 0 ? -(camPos.getX() / levelInfo.m_level_tile_width_px) : camPos.getX() / levelInfo.m_level_tile_width_px;
	
	uint32_t startRow = startRowInput % levelInfo.m_level_height_in_tile;
	uint32_t startColumn = startColumnInput % levelInfo.m_level_width_in_tile;
	

	if (startRow >= levelInfo.m_level_height_in_tile - (wh / levelInfo.m_level_tile_height_px))
	{
		startRow = levelInfo.m_level_height_in_tile - (wh / levelInfo.m_level_tile_height_px);
	}	
	if (startColumn >= levelInfo.m_level_width_in_tile - (ww / levelInfo.m_level_tile_width_px))
	{
		startColumn = levelInfo.m_level_width_in_tile - (ww / levelInfo.m_level_tile_width_px);
	}
	
	const uint32_t endRow = startRow + (wh / levelInfo.m_level_tile_height_px);
	const uint32_t endColumn = startColumn + (ww / levelInfo.m_level_tile_width_px);
	
//	printf("viewport.y: %d\n", viewport.y);
//	printf("viewport.x: %d\n", viewport.x);
//	printf("startRow: %u\n", startRow);
//	printf("startColumn: %u\n", startColumn);
//	printf("endRow: %u\n", endRow);
//	printf("endColumn: %u\n", endColumn);
	
	for (uint32_t row = startRow; row < endRow; row++)
	{
		for (uint32_t column = startColumn; column < endColumn; column++)
		{
			m_tiles[row * levelInfo.m_level_width_in_tile + column]->draw();
		}
	}
}

void TileLayer::setGids(const std::string& strGids) {
	std::string tmpStr;
	
	for (uint32_t i = 0; i < strGids.size(); i++)
	{
		if (strGids[i] != ',' && strGids[i] != ' ' && strGids[i] != '\n')
		{
			tmpStr += strGids[i];
		}
		else {
			if (tmpStr.size() > 0)
			{
				m_gids.push_back(std::stoi(tmpStr));
			}
			tmpStr.clear();
		}
	}
}
void TileLayer::printGids(const LevelInfo& levelInfo) {
	
	for (uint32_t row = 0; row < levelInfo.m_level_height_in_tile; row++)
	{
		for (uint32_t column = 0; column < levelInfo.m_level_width_in_tile; column++)
		{
			printf(" %d ", m_gids[row * levelInfo.m_level_width_in_tile + column]);
		}
		printf("\n");
	}
}


void TileLayer::setTiles(const LevelInfo& levelInfo) {
	
	Tile* newTile = nullptr;
	VectorFloat2D tilePosition;
	SDL_Rect tileSrcRect;
	SDL_Texture* tilesheet = nullptr;
	int32_t gid = 0;
	bool tileInvisible = false;
	
	for (uint32_t row = 0; row < levelInfo.m_level_height_in_tile; row++)
	{
		for (uint32_t column = 0; column < levelInfo.m_level_width_in_tile; column++)
		{
			newTile = new Tile();
			
			tilePosition = VectorFloat2D(column * levelInfo.m_level_tile_width_px,
				row * levelInfo.m_level_tile_height_px);
				
			gid = m_gids[row * levelInfo.m_level_width_in_tile + column];
			
			
			if (gid > 0)
			{
				tileInvisible = false;
				
				for (uint32_t ti = 0; ti < levelInfo.m_tilesets.size(); ti++)
				{
					int tilesheetIndex = 1;
					for (int32_t ti_tilecount = 0; ti_tilecount < levelInfo.m_tilesets[ti]->m_tile_count; 
						ti_tilecount++)
					{
						int tilesheet_width;
						int tilesheet_height;
						SDL_QueryTexture(levelInfo.m_tilesets[ti]->m_tilesheet, 0, 0, &tilesheet_width, &tilesheet_height);
						
						
						for (int ti_tc_row = 0; ti_tc_row < tilesheet_height / levelInfo.m_level_tile_height_px; ti_tc_row++)
						{
							for (int ti_tc_column = 0; ti_tc_column < tilesheet_width / levelInfo.m_level_tile_width_px; ti_tc_column++)
							{
								if (gid == tilesheetIndex)
								{
									tileSrcRect.x = ti_tc_column * levelInfo.m_level_tile_width_px;
									tileSrcRect.y = ti_tc_row * levelInfo.m_level_tile_height_px;
									tileSrcRect.w = levelInfo.m_level_tile_width_px;
									tileSrcRect.h = levelInfo.m_level_tile_height_px;
								}
								tilesheetIndex ++;
							}
						}
					}
					
					if (gid >= levelInfo.m_tilesets[ti]->m_first_gid &&
					gid < levelInfo.m_tilesets[ti]->m_first_gid + levelInfo.m_tilesets[ti]->m_tile_count)
					{
						tilesheet = levelInfo.m_tilesets[ti]->m_tilesheet;
					}
				}
			}
			else {
				tileInvisible = true;
			}
			
			newTile->setup(tilePosition, tileSrcRect, tilesheet, tileInvisible);
			m_tiles.push_back(newTile);
		}
	}
}
