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

#include "../../include/level/tile.h"
#include "../../include/miscellaneous/graphics.h"


void Tile::setup(VectorFloat2D position, SDL_Rect srcRect, SDL_Texture* tilesheet, bool invisible) {
	m_position = position;
	m_srcRect = srcRect;
	m_tilesheet = tilesheet;
	m_invisible = invisible;
}

void Tile::draw() {
	if (!m_invisible)
	{
		const SDL_Rect dstRect = { int(m_position.getX()), int(m_position.getY()),
		m_srcRect.w, m_srcRect.h };
		
		Graphics::instance().drawTexture(m_tilesheet, &m_srcRect, &dstRect);		
	}
}