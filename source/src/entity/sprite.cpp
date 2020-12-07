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

#include "../../include/entity/sprite.h"
#include "../../include/entity/entity_template.h"
#include "../../include/miscellaneous/graphics.h"
#include "../../include/miscellaneous/animation.h"



bool Sprite::load(EntityTemplate& entityTemplate) {
    m_currentAnimation = "___NONE";
	
	EntityTemplateInfo& _entity = entityTemplate.getEntityTemplateInfo();
	SpriteTemplateInfo& _sprite = entityTemplate.getSpriteTemplateInfo();
	
	m_position = _entity.m_position;
	m_size = _entity.m_size;
	
	if (_sprite.m_imgPath != "___NONE" && _sprite.m_imgName != "___NONE")
	{
		Graphics::instance().loadTexture(_sprite.m_imgPath,
			_sprite.m_imgName);
	}

	m_textureName = _sprite.m_imgName;
	
	std::map<std::string, Animation*> animCopyRef = _sprite.m_animations;
	for (m_animationsIt = animCopyRef.begin(); m_animationsIt != animCopyRef.end();
	m_animationsIt++)
	{
		m_animations[m_animationsIt->first] = new Animation();
		*(m_animations[m_animationsIt->first]) = *(m_animationsIt->second);
		
		m_animations[m_animationsIt->first]->setTarget(this);
		m_currentAnimation = m_animationsIt->first;
	}
    
    return true;
}
void Sprite::unload() {
    for (m_animationsIt = m_animations.begin(); m_animationsIt != m_animations.end();
	m_animationsIt++)
	{
		delete m_animationsIt->second;
	}
	m_animations.clear();
}
void Sprite::update(int32_t elapsedTime) {
    m_position += VectorFloat2D(0.f * elapsedTime, 0.f);
	
	if (m_currentAnimation != "___NONE")
	{
		m_animations[m_currentAnimation]->update(elapsedTime);
	}
}
void Sprite::draw() {
	if (m_currentAnimation != "___NONE")
	{
		m_animations[m_currentAnimation]->draw();
	}
}
