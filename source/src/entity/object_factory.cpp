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
#include "../../include/entity/object_factory.h"



ObjectFactory::~ObjectFactory() {
	for (m_containerIt = m_container.begin(); m_containerIt != m_container.end();
		m_containerIt++)
	{
		delete m_containerIt->second;
	}
	m_container.clear();
}
void ObjectFactory::registerObject(const std::string &_type, FactoryContainer *_container) {
	m_containerIt = m_container.find(_type);
	
	if (m_containerIt == m_container.end())
	{
		m_container[_type] = _container;
	} else {
		SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "ObjectFactory: this container is already registered!\n");
		delete _container;
	}
}
Entity *ObjectFactory::createObject(const std::string &_type, const Loader& loader) {
	m_containerIt = m_container.find(_type);
	
	if (m_containerIt != m_container.end())
	{
		return m_container[_type]->create(loader);
	} else {
		SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, "ObjectFactory: cannot find container\n");
	}
	
	return nullptr;
}