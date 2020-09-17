#include "../../include/base/animation.h"
#include "../../include/base/graphics.h"
#include "../../include/entity/sprite.h"


Animation::Animation() : m_pTarget(0), m_frameWidth(32), 
	m_frameHeight(32), m_row(0), m_column(0), m_startColumn(0),
	m_endColumn(3), m_frameDelay(200), m_frameDelayCount(0) {
	
	m_src.x = m_column * m_frameWidth;
	m_src.y = m_row * m_frameHeight;
	m_src.w = m_frameWidth;
	m_src.h = m_frameHeight;
}
Animation::Animation(int frameWidth, int frameHeight, int row, int startColumn,
	int endColumn, int frameDelay) : m_pTarget(0), m_frameWidth(frameWidth), 
	m_frameHeight(frameHeight), m_row(row), m_column(0), m_startColumn(startColumn),
	m_endColumn(endColumn), m_frameDelay(frameDelay), m_frameDelayCount(0) {
		
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
		m_pTarget->m_size.getX(), m_pTarget->m_size.getY() };
		
		Graphics::instance().drawTexture(m_pTarget->m_textureName, &m_src, &dst);	
	}
}
