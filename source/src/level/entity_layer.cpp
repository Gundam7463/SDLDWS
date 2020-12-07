/*
	 MIT License

	Copyright (c) 2020 Danrley Awesley Rodrigues Machado

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.
*/

#include "../../include/level/entity_layer.h"
#include "../../include/entity/entity_template.h"
#include "../../include/miscellaneous/application.h"



bool EntityLayer::load(tinyxml2::XMLElement* objectgroup) {

	for (tinyxml2::XMLElement* object = objectgroup->FirstChildElement(); object;
			object = object->NextSiblingElement())
	{
		if (std::string(object->Value()) == "object")
		{
			Entity* entity = nullptr;
			EntityTemplate entityTemplate;

			tinyxml2::XMLElement* property = object->FirstChildElement()->FirstChildElement();
			
			if (std::string(property->Value()) == "property")
			{
				entityTemplate.load(property->Attribute("value"));
				/** If entity is on tiled editor positive for axis x and y, accept the tiled editor
				 * x,y coordinate values.
				 */
				if (object->FloatAttribute("x") >= 0.f && object->FloatAttribute("y") >= 0.f)
				{
					VectorFloat2D newPosition(object->FloatAttribute("x"), object->FloatAttribute("y"));
					entityTemplate.getEntityTemplateInfo().m_position = newPosition;
				}
				
				entity = Application::instance().getFactory().createObject(entityTemplate.getObjectName(), entityTemplate);
				if (entity)
				{
					m_entities.push_back(entity);
				}
				else 
				{
					return false;
				}
			}
		}
	}
	
	return true;
}
void EntityLayer::unload() {
	for (uint32_t i = 0; i < m_entities.size(); i++)
	{
		m_entities[i]->unload();
		delete m_entities[i];
	}
	m_entities.clear();
}

void EntityLayer::update(int32_t elapsedTime) {
	for (uint32_t i = 0; i < m_entities.size(); i++)
	{
		m_entities[i]->update(elapsedTime);
	}
}
void EntityLayer::draw() {
	for (uint32_t i = 0; i < m_entities.size(); i++)
	{
		m_entities[i]->draw();
	}
}
