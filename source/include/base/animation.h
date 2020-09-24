/** The animation class.
 * 
 * IS: Animation for our games.
 * 
 * WHERE: Contained on Sprite objects and Sprite Loader.
 * 
 * HOW: 1- An container filled by Sprite Loader. 
 * 		2- Sprite loads an copy.
 */

#pragma once 

#include <SDL2/SDL_rect.h>


class Sprite;

class Animation {
public:
	//Alternative setup
	Animation();
	
	/** Animation ( int frameWidth, int frameHeight, int row, int startColumn,
	 * 				int endColumn, int frameDelay )
	 * 
	 * @brief Constructor setup.
	 * 
	 * @param frameWidth the horizontal frame width for each square.
	 * @param frameHeight the vertical frame height for each square.
	 * @param row the vertical line of this animation on the sprite sheet.
	 * @param startColumn the start horizontal column on the sprite sheet.
	 * @param endColumn the end square/frame.
	 * @param frameDelay the ms(milliseconds) delay between each frame.
	 */
    Animation(int frameWidth, int frameHeight, int row, int startColumn,
	int endColumn, int frameDelay);

	/** void setTarget ( Sprite* sprite )
	 * 
	 * @brief Select the target to this animation work on.
	 * 
	 * @param target one sprite object pointer.
	 */
    void setTarget(Sprite* target);
    
	/** void update ( int elapsedTime ) 
	 * 
	 * @brief do the logic.
	 * 
	 * @param elapsedTime the ms elapsed between each iteration of the game.
	 */
    void update(int elapsedTime);
    
	//render
    void draw();
private:
    
    Sprite* m_pTarget;//target pointer reference.
    
    int m_frameWidth;
    int m_frameHeight;
    
    int m_row;
    int m_column;
    int m_startColumn;
    int m_endColumn;
    
    SDL_Rect m_src;//Represents the frame on the sprite sheet texture.
    
    int m_frameDelay;
    int m_frameDelayCount;//the frameDelay counter.
};
