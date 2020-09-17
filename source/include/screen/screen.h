#pragma once 

#include <vector>
#include "../base/tinyxml2.h"
#include "../entity/entity.h"


class Screen {
public:
	void unload();
	bool load(tinyxml2::XMLElement *element);

	void update(int elapsedTime);
	void draw();
	
private:
	std::vector<Entity*> m_entities;
};
