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
#include "screen.h"
#include "../miscellaneous/tinyxml2.h"



class ScreenManager {
public:
	ScreenManager();

	void unload();

	bool loadScreenFiles();
	
	bool empty() { return m_empty; }
	
	void setScreen(const std::string& name);
	
	void popScreen(const std::string& name);
	
	void update(int32_t elapsedTime);
	void draw();
	
private:
	std::map<std::string, Screen*> m_screens;
	std::map<std::string, Screen*>::iterator m_screensIt;
	std::map<std::string, tinyxml2::XMLDocument*> m_screensFiles;
	std::map<std::string, tinyxml2::XMLDocument*>::iterator m_screensFilesIt;
	
	std::string m_currentScreen;
	bool m_empty;
	
	bool loadScreen(const std::string& name);
};
