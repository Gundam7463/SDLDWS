#include "../../include/level/level.h"


bool Level::load(const Loader* loader) {
	return true;
}
void Level::unload() {
	for (unsigned int i = 0; i < m_layers.size(); i++)
	{
		m_layers[i]->unload();
		delete m_layers[i];
	}
	m_layers.clear();
}
void Level::update(int elapsedTime) {
	for (unsigned int i = 0; i < m_layers.size(); i++)
	{
		m_layers[i]->update(elapsedTime);
	}
}
void Level::draw() {
	for (unsigned int i = 0; i < m_layers.size(); i++)
	{
		m_layers[i]->draw();
	}
}