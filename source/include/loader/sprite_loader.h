#pragma once 

#include <map>
#include <SDL2/SDL_rect.h>
#include "loader.h"
#include "../base/vector_2d.h"


class Animation;

class SpriteLoader : public Loader {
public:

	~SpriteLoader();
	
    virtual bool load(const std::string& path);
    
    const VectorFloat2D& getPosition() const { return m_position; }
    const VectorInt2D& getSize() const { return m_size; }
    const std::string& getImgPath() const { return m_imgPath; }
    const std::string& getImgName() const { return m_imgName; }
	
	std::map<std::string, Animation*> getAnimations() const { return m_animations; }
    
private:
    VectorFloat2D m_position;
    VectorInt2D m_size;
    
    std::string m_imgPath;
    std::string m_imgName;
    
    std::map<std::string, Animation*> m_animations;
};
