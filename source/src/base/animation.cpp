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

#include "../../include/base/animation.h"
#include "../../include/base/graphics.h"
#include "../../include/entity/sprite.h"


Animation::Animation() : m_pTarget(nullptr), m_frameWidth(32), 
	m_frameHeight(32), m_row(0), m_column(0), m_startColumn(0),
	m_endColumn(3), m_frameDelay(200), m_frameDelayCount(0) {
	
	m_src.x = m_column * m_frameWidth;
	m_src.y = m_row * m_frameHeight;
	m_src.w = m_frameWidth;
	m_src.h = m_frameHeight;
}
Animation::Animation(int frameWidth, int frameHeight, int row, int startColumn,
	int endColumn, int frameDelay) : m_pTarget(nullptr), m_frameWidth(frameWidth), 
	m_frameHeight(frameHeight), m_row(row), m_column(0), m_startColumn(startColumn),
	m_endColumn(endColumn), m_frameDelay(frameDelay), m_frameDelayCount(0) {
		
	//fill our start frame
	m_src.x = m_column * m_frameWidth;
	m_src.y = m_row * m_frameHeight;
	m_src.w = m_frameWidth;
	m_src.h = m_frameHeight;
}
void Animation::setTarget(Sprite *target) {
    m_pTarget = target;
}

void Animation::update(int elapsedTime) {
    if ((m_frameDelayCount += elapsedTime) > m_frameDelay)
    {
        m_frameDelayCount = 0;
		
        m_src.x = m_column * m_frameWidth;
        m_src.y = m_row * m_frameHeight;
        m_src.w = m_frameWidth;
        m_src.h = m_frameHeight;
        
        if (++m_column > m_endColumn)
        {
            m_column = m_startColumn;
        }
    }
}
void Animation::draw() {
	if (m_pTarget)
	{
		const SDL_Rect dst = { int(m_pTarget->m_position.getX()), int(m_pTarget->m_position.getY()), 
		m_frameWidth, m_frameHeight };
		
		//Use the sprite texture and our data to draw the animation
		Graphics::instance().drawTexture(m_pTarget->m_textureName, &m_src, &dst);	
	}
}
