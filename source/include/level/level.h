#pragma once 

#include <string>
#include <vector>
#include <map>
#include "layer.h"
#include "../base/tinyxml2.h"


class Level {
public:
    bool loadLevelFiles(const Loader* loader);
    void unload();
	
    void update(int elapsedTime);
    void draw();
	
private:
	std::vector<Layer*> m_layers;
	
	std::map<std::string, tinyxml2::XMLDocument*> m_levelFiles;
	std::map<std::string, tinyxml2::XMLDocument*>::iterator m_levelFilesIt;
};