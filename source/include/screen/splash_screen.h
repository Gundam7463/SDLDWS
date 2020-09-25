#pragma once 


#include "screen.h"



class SplashScreen : public Screen {
public:
	virtual void unload();
	virtual bool load(tinyxml2::XMLElement *element);

	virtual void update(int elapsedTime);
	virtual void draw();
};