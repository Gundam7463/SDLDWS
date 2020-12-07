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

#include "../../include/entity/button.h"
#include "../../include/miscellaneous/graphics.h"
#include "../../include/input/input_manager.h"


bool Button::load(EntityTemplate& entityTemplate) {
	bool success = Sprite::load(entityTemplate);
	m_text = entityTemplate.getButtonTemplateInfo().m_text;
	
	return success;
}
void Button::unload() {
	Sprite::unload();
}

void Button::update(int32_t elapsedTime) {
	
	int mx, my;
	InputManager::instance().getMousePosition(&mx, &my);
	const SDL_Rect buttonRect = { (int)m_position.getX(), (int)m_position.getY(), m_size.getX(),
	m_size.getY() };
	const SDL_Rect mouseRect = { mx, my, 4, 4 };
	
	if (SDL_HasIntersection(&buttonRect, &mouseRect))
	{
		m_bHighlighted = true;
	}
	else {
		m_bHighlighted = false;
	}
}
void Button::draw() {
	
	VectorInt2D pos((int32_t)m_position.getX(), (int32_t)m_position.getY());
	SDL_Color color = { 0xff, 0xff, 0xff, 0xff };
	
	if (m_bHighlighted)
	{
		const SDL_Rect rect = { int(m_position.getX()), int(m_position.getY()) + m_size.getY() / 4, 
		m_size.getX(), m_size.getY() };
		Graphics::instance().drawFillRect(&rect, 100, 10, 210);
	}
	Graphics::instance().drawTextSolid("barlow32", m_text.c_str(), color, 0, pos); 
}