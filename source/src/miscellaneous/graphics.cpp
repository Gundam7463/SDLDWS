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

#include <cstdio>
#include <string>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "../../include/miscellaneous/graphics.h"


extern std::string gRootDir;//our default /res/ path


void Graphics::unload() {
    
    for (m_textureListIt = m_textureList.begin(); m_textureListIt != m_textureList.end(); m_textureListIt++)
    {
        SDL_DestroyTexture(m_textureListIt->second);
    }
    m_textureList.clear();
    
    for (m_fontListIt = m_fontList.begin(); m_fontListIt != m_fontList.end(); m_fontListIt++)
    {
        TTF_CloseFont(m_fontListIt->second);
    }
    m_fontList.clear();
    
    if (m_pRenderer)
    {
        SDL_DestroyRenderer(m_pRenderer);
    }
    if (m_pWindow)
    {
        SDL_DestroyWindow(m_pWindow);
    }
}
void Graphics::loadTexture(const std::string& path, const std::string& index) {
    m_textureListIt = m_textureList.find(index);
    
    if (m_textureListIt == m_textureList.end())
    {
		SDL_Texture* texture = this->loadTexture(path);

        if (texture)
        {
			m_textureList[index] = texture;   
        }
    }
}
SDL_Texture* Graphics::loadTexture(const std::string& path) {
	std::string finalPath;
	finalPath = gRootDir;
	finalPath += "/img/";
	finalPath += path;
	
	
	SDL_Surface *surfaceLoaded = IMG_Load(finalPath.c_str());
	SDL_Texture *texture = nullptr;

	if (surfaceLoaded)
	{
		SDL_SetColorKey(surfaceLoaded, SDL_TRUE, SDL_MapRGB(surfaceLoaded->format, 255, 0, 255));
		texture = SDL_CreateTextureFromSurface(m_pRenderer, surfaceLoaded);
		
		SDL_FreeSurface(surfaceLoaded);
	}
	
	return texture;
}
void Graphics::loadFont(const std::string& path, const std::string& index, uint8_t ptsize) {
    
    m_fontListIt = m_fontList.find(index);
    
    if (m_fontListIt == m_fontList.end())
    {
        std::string finalPath;
        finalPath = gRootDir;
        finalPath += "/font/";
        finalPath += path;
        
        TTF_Font *font = TTF_OpenFont(finalPath.c_str(), ptsize);
        
        if (font)
        {
            m_fontList[index] = font;
        } 
    }
}
void Graphics::getWindowSize(int* w, int* h) {
    SDL_GetWindowSize(m_pWindow, w, h);
}
void Graphics::setRenderColor(Uint8 r, Uint8 g, Uint8 b) {
    SDL_SetRenderDrawColor(m_pRenderer, r, g, b, 0xFF);
}
void Graphics::setViewport(const SDL_Rect* rect) {
    SDL_RenderSetViewport(m_pRenderer, rect);
}
void Graphics::clearColor() {
    SDL_RenderClear(m_pRenderer);
}
void Graphics::renderPresent() {
    SDL_RenderPresent(m_pRenderer);
}
void Graphics::drawTexture(const std::string& index, const SDL_Rect* srcRect, const SDL_Rect* dstRect, const double angle,
    const SDL_Point* center, const SDL_RendererFlip flip) {
    
    m_textureListIt = m_textureList.find(index);
    if (m_textureListIt != m_textureList.end())
    {
        SDL_RenderCopyEx(m_pRenderer, m_textureList[index], srcRect, dstRect, angle, center, flip);
    }
}
void Graphics::drawTexture(SDL_Texture* texture, const SDL_Rect* srcRect, const SDL_Rect* dstRect, const double angle,
    const SDL_Point* center, const SDL_RendererFlip flip) {
    
	SDL_RenderCopyEx(m_pRenderer, texture, srcRect, dstRect, angle, center, flip);
}
void Graphics::drawTextSolid(const std::string& index, const char* text, SDL_Color fg, const SDL_Rect* srcRect, 
        VectorInt2D position) {
    
    m_fontListIt = m_fontList.find(index);
    if (m_fontListIt != m_fontList.end())
    {            
        TTF_Font *font = m_fontList[index];
        SDL_Surface* surface = TTF_RenderUTF8_Solid(font, text, fg);
        
        SDL_Texture *texture = SDL_CreateTextureFromSurface(m_pRenderer, surface);
		
		
		const SDL_Rect dstRect = { position.getX(), position.getY(), surface->w, surface->h };
        
        SDL_RenderCopy(m_pRenderer, texture, srcRect, &dstRect);
        SDL_DestroyTexture(texture);
		
        SDL_FreeSurface(surface);
    }
}
SDL_Texture* Graphics::drawTextSolidToTexture(const std::string& index, SDL_Rect* textureRect, const char* text, 
	SDL_Color fg) {
		
	SDL_Texture *texture = nullptr;
			
    m_fontListIt = m_fontList.find(index);
    if (m_fontListIt != m_fontList.end())
    {            
        TTF_Font *font = m_fontList[index];
        SDL_Surface* surface = TTF_RenderUTF8_Solid(font, text, fg);
        
        texture = SDL_CreateTextureFromSurface(m_pRenderer, surface);
		
		if (textureRect)
		{
			textureRect->x = textureRect->y = 0;
			textureRect->w = surface->w;
			textureRect->h = surface->h;
		}
		
        SDL_FreeSurface(surface);
    }
	
	return texture;
}
Graphics::Graphics() {
    
    m_pWindow = SDL_CreateWindow("SDLDWS", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_SOFTWARE);

    if (!m_pWindow || !m_pRenderer)
    {
        fprintf(stdout, "Error on create window, renderer: Graphics constructor\n");
    }
}
