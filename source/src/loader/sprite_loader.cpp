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

#include "../../include/base/tinyxml2.h"
#include "../../include/loader/sprite_loader.h"
#include "../../include/base/animation.h"

extern std::string gRootDir;



SpriteLoader::~SpriteLoader() {
	for (std::map<std::string, Animation*>::iterator it = m_animations.begin(); 
	it != m_animations.end(); it++)
	{
		delete it->second;
	}
	m_animations.clear();
}
bool SpriteLoader::load(const std::string& path) {
    std::string finalPath = gRootDir;
    finalPath += "/obj/";
    finalPath += path;
    
    tinyxml2::XMLDocument doc;
    
    doc.LoadFile(finalPath.c_str());
    if (doc.Error())
    {
        doc.PrintError();
        return false;
    }
    
    tinyxml2::XMLElement *root = doc.FirstChildElement();
    
    if (std::string(root->Attribute("type")) == "sprite-loader")
    {
        for (tinyxml2::XMLElement *element = root->FirstChildElement(); element; element = element->NextSiblingElement())
        {
            if (std::string(element->Value()) == "position")
            {
                m_position.setX(element->FloatAttribute("x"));
                m_position.setY(element->FloatAttribute("y"));                
            }
            if (std::string(element->Value()) == "size")
            {
                m_size.setX(element->IntAttribute("width"));
                m_size.setY(element->IntAttribute("height"));
            }
            if (std::string(element->Value()) == "img")
            {
                m_imgPath = element->Attribute("path");
                m_imgName = element->Attribute("nameID");
            }
            
            if (std::string(element->Value()) == "animation")
            {
				for (tinyxml2::XMLElement *anim = element->FirstChildElement(); 
				anim; anim = anim->NextSiblingElement())
                {
				
					std::string name = anim->Attribute("name");
					int frameWidth = anim->IntAttribute("frame-width");
					int frameHeight = anim->IntAttribute("frame-height");
					int row = anim->IntAttribute("row");
					int startColumn = anim->IntAttribute("start-column");
					int endColumn = anim->IntAttribute("end-column");
					int frameDelay = anim->IntAttribute("frame-delay");
					
					
					Animation *newAnim = new Animation(frameWidth, frameHeight, row, startColumn,
					endColumn, frameDelay);
					m_animations[name] = newAnim;				
				}
            }
        }
    }
    
    return true;
}
