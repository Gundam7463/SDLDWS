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

#include <string>
#include <map>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "vector_2d.h"



class Graphics {
public:
    static Graphics& instance() {
        static Graphics graphics;
        return graphics;
    }

    void unload();
    
    void loadTexture(const std::string& path, const std::string& index);
    
    void loadFont(const std::string& path, const std::string& index, int ptsize);
    
    void getWindowSize(int* w, int* h);
    
    void setRenderColor(Uint8 r, Uint8 g, Uint8 b);
    
    void setViewport(const SDL_Rect* rect);
    
    void clearColor();
	
    void renderPresent();
    
    void drawTexture(const std::string& index, const SDL_Rect* srcRect=0, const SDL_Rect* dstRect=0, const double angle=0.0,
        const SDL_Point* center=0, const SDL_RendererFlip flip=SDL_FLIP_NONE);
        
    void drawTextSolid(const std::string& index, const char* text, SDL_Color fg, const SDL_Rect* srcRect, 
        VectorInt2D position);
    
private:
    Graphics();

    SDL_Window *m_pWindow;
    SDL_Renderer *m_pRenderer;
    
    std::map<std::string, SDL_Texture*> m_textureList;
    std::map<std::string, SDL_Texture*>::iterator m_textureListIt;
    
    std::map<std::string, TTF_Font*> m_fontList;
    std::map<std::string, TTF_Font*>::iterator m_fontListIt;
};
