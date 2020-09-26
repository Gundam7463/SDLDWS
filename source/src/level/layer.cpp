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

#include "../../include/level/layer.h"


void Layer::unload() {
	for (unsigned int i = 0; i < m_entities.size(); i++)
	{
		m_entities[i]->unload();
		delete m_entities[i];
	}
	m_entities.clear();
}
void Layer::pushEntity(Entity *e) {
	m_entities.push_back(e);
}
void Layer::update(int elapsedTime) {
	for (unsigned int i = 0; i < m_entities.size(); i++)
	{
		m_entities[i]->update(elapsedTime);
	}
}
void Layer::draw() {
	for (unsigned int i = 0; i < m_entities.size(); i++)
	{
		m_entities[i]->draw();
	}
}
Layer::Layer() {
}