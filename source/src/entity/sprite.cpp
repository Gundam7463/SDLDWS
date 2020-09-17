#include "../../include/entity/sprite.h"
#include "../../include/loader/sprite_loader.h"
#include "../../include/base/graphics.h"
#include "../../include/base/animation.h"



bool Sprite::load(const Loader* loader) {
    const SpriteLoader* spriteLoader = dynamic_cast<const SpriteLoader*> (loader);
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
void Sprite::update(int elapsedTime) {
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
