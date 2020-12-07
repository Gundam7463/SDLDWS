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

#pragma once 

#include <map>
#include <SDL2/SDL_rect.h>
#include "../miscellaneous/vector_2d.h"


class Animation;




struct EntityTemplateInfo {
	
	EntityTemplateInfo() {
	}
	
	EntityTemplateInfo(VectorFloat2D position, VectorInt2D _size) : m_position(position),
	m_size(_size) {
	}
	
	
	
	VectorFloat2D m_position;
	VectorInt2D m_size;
};
struct SpriteTemplateInfo {
	
	SpriteTemplateInfo() : m_imgPath("___NONE"), m_imgName("___NONE") {
	}
	
	SpriteTemplateInfo(const std::string& imgPath, const std::string& imgName) : 
	m_imgPath(imgPath), m_imgName(imgName) {
	}
	
	
	
	std::string m_imgPath;
	std::string m_imgName;
	std::map<std::string, Animation*> m_animations;
};
struct ButtonTemplateInfo {
	
	ButtonTemplateInfo() : m_text("none") {
	}
	
	ButtonTemplateInfo(const std::string& text) : m_text(text) {
	}
	
	
	
	std::string m_text;
};

class EntityTemplate {
public:

	EntityTemplate() { }
	~EntityTemplate();

	
    bool load(const std::string& path);
    
	EntityTemplateInfo& getEntityTemplateInfo() { return m_entityTemplateInfo; }
	SpriteTemplateInfo& getSpriteTemplateInfo() { return m_spriteTemplateInfo; }
	ButtonTemplateInfo& getButtonTemplateInfo() { return m_buttonTemplateInfo; }
	
	std::string& getObjectName() { return m_objectName; }
    
private:
	std::string m_objectName;
	
	EntityTemplateInfo m_entityTemplateInfo;
	SpriteTemplateInfo m_spriteTemplateInfo;
	ButtonTemplateInfo m_buttonTemplateInfo;
};
