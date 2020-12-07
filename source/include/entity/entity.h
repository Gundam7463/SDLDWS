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

/** The Entity class.
 * 
 * IS: All kind of things for our games, you can define as triggers entity's.
 * 
 * WHERE: Contained on Screens, Level.
 * 
 * HOW WORKS: 
 * 		As a polymorphic object.
 */

#pragma once 

#include <string>
#include <SDL2/SDL_rect.h>
#include "../miscellaneous/vector_2d.h"
#include "../entity/entity_template.h"


class Entity {
public:
	virtual ~Entity() { }//get rid of some warnings

    /** virtual bool load ( EntityTemplate& entityTemplate ) = 0;
	 * 
	 * @brief Load and initialize the entity.
	 * 
	 * @param entityTemplate the entityTemplate reference.
	 * 
	 * @return true on success or, false in case of errors.
	 */
    virtual bool load(EntityTemplate& entityTemplate) = 0;
	
    /** virtual void unload ( ) = 0;
	 * 
	 * @brief unload the entity loaded values.
	 */
    virtual void unload() = 0;
    
    /** virtual void update ( int32_t elapsedTime ) { }
	 * 
	 * @brief Update the entity states.
	 * 
	 * @param elapsedTime the ms time delay in each iteration
	 */
    virtual void update(int32_t elapsedTime) { }
	
	//Draw's if it needed.
    virtual void draw() { }
    
protected:
	//All entities must have a position and size.
    VectorFloat2D m_position;
    VectorInt2D m_size;
};
