#pragma once 

#include <string>
#include <map>
#include "entity.h"
#include "../loader/loader.h"


class FactoryContainer {
public:
	virtual ~FactoryContainer() { }

	virtual Entity* create(const Loader *loader) = 0;
};



class ObjectFactory {
public:
	~ObjectFactory();

	void registerObject(const std::string &_type, FactoryContainer *_container);
	Entity *createObject(const std::string &_type, const Loader *loader);
	
private:
	std::map<std::string, FactoryContainer*> m_container;
	std::map<std::string, FactoryContainer*>::iterator m_containerIt;
};