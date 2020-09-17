#pragma once 

#include <string>
#include <vector>
#include "../entity/entity.h"


class Layer {
public:
	virtual ~Layer() { }

	virtual void unload();
	virtual void pushEntity(Entity *e);

	virtual void update(int elapsedTime);
	virtual void draw();

	virtual const std::string getType() const { return "NONE"; }
private:
	Layer();

	std::vector<Entity*> m_entities;
};