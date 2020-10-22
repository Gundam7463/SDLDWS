#pragma once 

#include <cstdint>
#include <string>
#include <SDL2/SDL.h>
#include "../miscellaneous/graphics.h"


struct Tileset {
	Tileset(int16_t first_gid, const std::string& name, uint8_t tile_width, uint8_t tile_height,
	int32_t tile_count, const std::string& image_source) 
	: m_first_gid(first_gid), m_name(name), m_tile_width(tile_width), m_tile_height(tile_height),
	 m_tile_count(tile_count), m_tilesheet(nullptr) {
		
		m_tilesheet = Graphics::instance().loadTexture(image_source);
	}
	~Tileset() {
		if (m_tilesheet)
		{
			SDL_DestroyTexture(m_tilesheet);
		}
		m_tilesheet = 0;
	}
	
	int16_t m_first_gid;
	std::string m_name;
	uint8_t m_tile_width;
	uint8_t m_tile_height;
	int32_t m_tile_count;
	SDL_Texture* m_tilesheet;
};
