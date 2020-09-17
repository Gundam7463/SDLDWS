#pragma once 

#include <string>
#include <vector>
#include "layer.h"


class Level : public Entity {
public:
    virtual bool load(const Loader* loader);
    virtual void unload();
	
    virtual void update(int elapsedTime);
    virtual void draw();
private:
	std::vector<Layer*> m_layers;
};