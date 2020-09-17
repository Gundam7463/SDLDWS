#include "../../include/level/layer.h"


void Layer::unload() {
	for (unsigned int i = 0; i < m_entities.size(); i++)
	{
		m_entities[i]->unload();
		delete m_entities[i];
	}
	m_entities.clear();
}
void Layer::pushEntity(Entity *e) {
	m_entities.push_back(e);
}
void Layer::update(int elapsedTime) {
	for (unsigned int i = 0; i < m_entities.size(); i++)
	{
		m_entities[i]->update(elapsedTime);
	}
}
void Layer::draw() {
	for (unsigned int i = 0; i < m_entities.size(); i++)
	{
		m_entities[i]->draw();
	}
}
Layer::Layer() {
}