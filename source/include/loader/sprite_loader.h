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
