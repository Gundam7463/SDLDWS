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

/** The Object Factory class.
 * 
 * IS: The application object factory.
 * 
 * WHERE: Contained on Game object.
 * 
 * HOW WORKS: 
 * 		It can register new objects and create then.
 */

#pragma once 

#include <string>
#include <map>
#include "entity.h"


/** This is the interface for new objects containers
 */
class FactoryContainer {
public:
	virtual ~FactoryContainer() { }

	virtual Entity* create(EntityTemplate& entityTemplate) = 0;
};



class ObjectFactory {
public:
	~ObjectFactory();

	//simple register with _type which works like the name ID
	void registerObject(const std::string &_type, FactoryContainer *_container);
	Entity *createObject(const std::string &_type, EntityTemplate& entityTemplate);
	
private:
	std::map<std::string, FactoryContainer*> m_container;
	std::map<std::string, FactoryContainer*>::iterator m_containerIt;
};