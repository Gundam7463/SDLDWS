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
