#include <cstdio>
#include <string>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "../../include/base/graphics.h"


extern std::string gRootDir;


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
        std::string finalPath;
        finalPath = gRootDir;
        finalPath += "/img/";
        finalPath += path;
        
        
        SDL_Surface *surfaceLoaded = IMG_Load(finalPath.c_str());

        if (surfaceLoaded)
        {
            SDL_SetColorKey(surfaceLoaded, SDL_TRUE, SDL_MapRGB(surfaceLoaded->format, 255, 0, 255));
            SDL_Texture *texture = SDL_CreateTextureFromSurface(m_pRenderer, surfaceLoaded);
            
            if (texture)
            {
                m_textureList[index] = texture;   
            }   
            
            SDL_FreeSurface(surfaceLoaded);
        }
    }
}
void Graphics::loadFont(const std::string& path, const std::string& index, int ptsize) {
    
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
void Graphics::drawTextSolid(const std::string& index, const char* text, SDL_Color fg, const SDL_Rect* srcRect, 
        VectorInt2D position) {
    
    m_fontListIt = m_fontList.find(index);
    if (m_fontListIt != m_fontList.end())
    {            
        TTF_Font *font = m_fontList[index];
        SDL_Surface* surface = TTF_RenderUTF8_Solid(font, text, fg);
        
        SDL_Texture *texture = SDL_CreateTextureFromSurface(m_pRenderer, surface);
        SDL_FreeSurface(surface);
        
        int tw, th;
        SDL_QueryTexture(texture, 0, 0, &tw, &th);
        const SDL_Rect dstRect = { position.getX(), position.getY(), tw, th };
        
        SDL_RenderCopy(m_pRenderer, texture, srcRect, &dstRect);
        SDL_DestroyTexture(texture);
    }
}
Graphics::Graphics() {
    
    m_pWindow = SDL_CreateWindow("SDLDWS", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_SOFTWARE);

    if (!m_pWindow || !m_pRenderer)
    {
        fprintf(stdout, "Error on create window, renderer: Graphics constructor\n");
    }
}
