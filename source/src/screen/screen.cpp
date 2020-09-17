#include "../../include/screen/screen.h"
#include "../../include/loader/sprite_loader.h"
#include "../../include/entity/background.h"
#include "../../include/base/game.h"
 

void Screen::unload() {
	for (unsigned int i = 0; i < m_entities.size(); i++)
	{
		m_entities[i]->unload();
		delete m_entities[i];
	}
	m_entities.clear();
}
bool Screen::load(tinyxml2::XMLElement *element) {
	if (!element)
	{
		return false;
	}
	for (tinyxml2::XMLElement *e = element->FirstChildElement(); e; e = e->NextSiblingElement())
	{
		Loader *loader = nullptr;
		
		if (std::string(e->Value()) == "loader")
		{
			if (std::string(e->Attribute("type")) == "SpriteLoader")
			{
				loader = new SpriteLoader();
				
				if (!loader->load(e->Attribute("path")))
				{
					delete loader;
					return false;
				}
			}
			
			Entity *entity = Game::instance().getFactory().createObject(e->Attribute("obj"),
				loader);
			if (entity)
			{
				m_entities.push_back(entity);
			}
			else {
				delete loader;
				return false;
			}
		}
	}
	
	return true;
}
void Screen::update(int elapsedTime) {
	for (unsigned int i = 0; i < m_entities.size(); i++)
	{
		m_entities[i]->update(elapsedTime);
	}
}
void Screen::draw() {
	for (unsigned int i = 0; i < m_entities.size(); i++)
	{
		m_entities[i]->draw();
	}
}
