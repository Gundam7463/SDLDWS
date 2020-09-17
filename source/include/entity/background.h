#pragma once 

#include "../entity/sprite.h"
#include "../loader/loader.h"
#include "object_factory.h"


class Background : public Sprite {
public:
    virtual bool load(const Loader* loader);
    virtual void unload();
    
    virtual void update(int elapsedTime);
    virtual void draw();
	
};

class BackgroundFactoryContainer : public FactoryContainer {
public:
	virtual Entity* create(const Loader *loader) {
		
		Background *_instance = new Background();
		_instance->load(loader);
		
		return _instance;
	}
};