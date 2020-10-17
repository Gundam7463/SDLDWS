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
#include "../../include/loader/sprite_loader.h"
#include "../../include/base/graphics.h"
#include "../../include/base/animation.h"



bool Sprite::load(const void* loaderPtr) {
    const SpriteLoader* spriteLoader = (SpriteLoader*)loaderPtr;
    m_currentAnimation = "___NONE";
	
    if (spriteLoader != nullptr)
    {
        m_position = spriteLoader->getPosition();
        m_size = spriteLoader->getSize();
        
        Graphics::instance().loadTexture(spriteLoader->getImgPath(),
            spriteLoader->getImgName());

        m_textureName = spriteLoader->getImgName();
		
		std::map<std::string, Animation*> animCopyRef = spriteLoader->getAnimations();
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
    
    return false;
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
	
	if (m_currentAnimation != "__NONE")
	{
		m_animations[m_currentAnimation]->update(elapsedTime);
	}
}
void Sprite::draw() {
	if (m_currentAnimation != "__NONE")
	{
		m_animations[m_currentAnimation]->draw();
	}
}
