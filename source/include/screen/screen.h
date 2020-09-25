#pragma once 

#include <vector>
#include "../base/tinyxml2.h"
#include "../entity/entity.h"


class Screen {
public:
	virtual ~Screen() { }

	virtual void unload();
	virtual bool load(tinyxml2::XMLElement *element);

	virtual void update(int elapsedTime);
	virtual void draw();
	
private:
	std::vector<Entity*> m_entities;
};
