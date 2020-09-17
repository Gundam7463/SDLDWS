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
		SDL_Log("ObjectFactory: this container is already registered!\n");
	}
}
Entity *ObjectFactory::createObject(const std::string &_type, const Loader *loader) {
	m_containerIt = m_container.find(_type);
	
	if (m_containerIt != m_container.end())
	{
		return m_container[_type]->create(loader);
	} else {
		SDL_Log("ObjectFactory: cannot find container\n");
		return nullptr;	
	}
}