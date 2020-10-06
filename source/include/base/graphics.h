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

/** The Graphics class, holds everything about rendering.
 * 
 * IS: A singleton class that manipulates graphics and the window. 
 * 
 * WHERE: Initialized on game class, deallocated on game class, 
 * can be used on whatever you want. 
 * 
 * HOW WORKS: Simple call to instance method and it will create the window and set default values,
 * then choose the method that you will be using.
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

    /** void unload ( )
	 * 
	 * @brief Unload everything, call this on the end of the application after all deallocation.
	 */
    void unload();
    
    /** void loadTexture ( const std::string& path, const std::string& index )
	 * 
	 * @brief Load an texture from directory /res/img/
	 * 
	 * @param path The texture path before: /res/img/
	 * @param index The texture nameID.
	 */
    void loadTexture(const std::string& path, const std::string& index);
    
    /** void loadFont ( const std::string& path, const std::string& index, int ptsize )
	 * 
	 * @brief Load font from directory /res/font/
	 * 
	 * @param path The texture path before: /res/font/
	 * @param index The texture nameID.
	 * @param ptsize The font size in pt.
	 */
    void loadFont(const std::string& path, const std::string& index, int ptsize);
    
    /** void getWindowSize ( int* w, int* h )
	 * 
	 * @brief Get the window size in pixel.
	 * 
	 * @param w Width.
	 * @param h Height.
	 */
    void getWindowSize(int* w, int* h);
    
    /** void setRenderColor ( Uint8 r, Uint8 g, Uint8 b )
	 * 
	 * @brief Set current clear color from the renderer.
	 * 
	 * @param r Red value.
	 * @param g Green value.
	 * @param b Blue.
	 */
    void setRenderColor(Uint8 r, Uint8 g, Uint8 b);
    
    /** void setViewport ( const SDL_Rect* rect )
	 * 
	 * @brief Set the current viewport value.
	 * 
	 * @param rect The rect portion.
	 */
    void setViewport(const SDL_Rect* rect);
    
    /** void clearColor ( )
	 * 
	 * @brief Clear the current rendering target with the current color.
	 */
    void clearColor();
	
    /** void renderPresent ( )
	 * 
	 * @brief Draw from the backbuffer.
	 */
    void renderPresent();
    
    /** void drawTexture ( const std::string& index, const SDL_Rect* srcRect=nullptr, 
		const SDL_Rect* dstRect=nullptr, const double angle=0.0, const SDL_Point* center=nullptr, 
			const SDL_RendererFlip flip=SDL_FLIP_NONE )
	
	 * @brief Draw the texture on the rendering target.
	 * 
	 * @param index/texture The texture nameID or the texture pointer.
	 * @param srcRect The rectangle that represens the portion of the entire texture, 0 to
	 * get the entire texture.
	 * @param dstRect The rectangle that represents the position on the screen to be draw, 0
	 * to get the entire texture scaled to the entire screen.
	 * @param angle The angle of rotation.
	 * @param center The center of the rotation.
	 * @param flip The flip texture value, horizontally or vertically.
	 */
    void drawTexture(const std::string& index, const SDL_Rect* srcRect=nullptr, 
		const SDL_Rect* dstRect=nullptr, const double angle=0.0, const SDL_Point* center=nullptr, 
			const SDL_RendererFlip flip=SDL_FLIP_NONE);
		
    /** void drawTexture ( SDL_Texture* texture, const SDL_Rect* srcRect=nullptr, 
		const SDL_Rect* dstRect=nullptr, const double angle=0.0, const SDL_Point* center=nullptr, 
			const SDL_RendererFlip flip=SDL_FLIP_NONE )
	
	 * @brief Draw the texture on the rendering target.
	 * 
	 * @param index/texture The texture nameID or the texture pointer.
	 * @param srcRect The rectangle that represens the portion of the entire texture, 0 to
	 * get the entire texture.
	 * @param dstRect The rectangle that represents the position on the screen to be draw, 0
	 * to get the entire texture scaled to the entire screen.
	 * @param angle The angle of rotation.
	 * @param center The center of the rotation.
	 * @param flip The flip texture value, horizontally or vertically.
	 */	
	void drawTexture(SDL_Texture* texture, const SDL_Rect* srcRect=nullptr, 
		const SDL_Rect* dstRect=nullptr, const double angle=0.0, const SDL_Point* center=nullptr,
			const SDL_RendererFlip flip=SDL_FLIP_NONE);
	
    /** void drawTextSolid ( const std::string& index, const char* text, SDL_Color fg, 
	 * 	const SDL_Rect* srcRect, VectorInt2D position )
	 * 
	 * @brief Draw a text on screen, this operation may be slow.
	 * 
	 * @param index The font nameID.
	 * @param text The text that will be rendering to the screen.
	 * @param fg The color to the text.
	 * @param srcRect The rectangle that represents the portion of the entire texture text, 
	 * 0 to get the entire texture.
	 * @param position 2D(x,y) vector that represents in pixel, the position of the text on screen.
	 */
    void drawTextSolid(const std::string& index, const char* text, SDL_Color fg, const SDL_Rect* srcRect, 
        VectorInt2D position);
		
    /** SDL_Texture* drawTextSolid ( const std::string& index, SDL_Rect* textureRect, const char* text, 
	 * 	SDL_Color fg )
	 * 
	 * @brief Draw a text to texture, this operation can be fast if you draw in a different time interval.
	 * 
	 * @param index The font nameID.
	 * @param textureRect the rectangle of the entire texture.
	 * @param text The text that will be rendering to the screen.
	 * @param fg The color to the text.
	 * 
	 * @return Returns the new texture text created.
	 */
    SDL_Texture* drawTextSolidToTexture(const std::string& index, SDL_Rect* textureRect, const char* text, 
		SDL_Color fg);
    
private:
    Graphics();//constructor that set default values.

    SDL_Window *m_pWindow;
    SDL_Renderer *m_pRenderer;
    
    std::map<std::string, SDL_Texture*> m_textureList;//The list of all texture loaded by loadTexture.
    std::map<std::string, SDL_Texture*>::iterator m_textureListIt;
    
    std::map<std::string, TTF_Font*> m_fontList;//The list of all font loaded by loadFont.
    std::map<std::string, TTF_Font*>::iterator m_fontListIt;
};
