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

#include "../../include/screen/screen.h"
#include "../../include/miscellaneous/loader.h"
#include "../../include/miscellaneous/game.h"
#include "../../include/miscellaneous/graphics.h"
 

void Screen::unload() {
	for (uint32_t i = 0; i < m_entities.size(); i++)
	{
		m_entities[i]->unload();
		delete m_entities[i];
	}
	m_entities.clear();
}
bool Screen::load(tinyxml2::XMLElement *element) {
	if (!element)
	{
		return false;
	}
	for (tinyxml2::XMLElement *e = element->FirstChildElement(); e; e = e->NextSiblingElement())
	{
		if (std::string(e->Value()) == "loader")
		{
			Loader loader;
			
			if (!loader.load(e->Attribute("path")))
			{
				return false;
			}
			
			Entity *entity = Game::instance().getFactory().createObject(e->Attribute("obj"),
				loader);
			if (entity)
			{
				m_entities.push_back(entity);
			}
			else {
				return false;
			}
		}
	}
	
	int ww, wh;
	Graphics::instance().getWindowSize(&ww, &wh);
	Game::instance().getCamera().init(ww, wh);
	
	return true;
}
void Screen::update(int32_t elapsedTime) {
	for (uint32_t i = 0; i < m_entities.size(); i++)
	{
		m_entities[i]->update(elapsedTime);
	}
}
void Screen::draw() {
	for (uint32_t i = 0; i < m_entities.size(); i++)
	{
		m_entities[i]->draw();
	}
}
