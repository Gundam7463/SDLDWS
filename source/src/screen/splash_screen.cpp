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

#include "../../include/screen/splash_screen.h"
#include "../../include/miscellaneous/application.h"

void SplashScreen::unload() {
	Screen::unload();
}
bool SplashScreen::load(tinyxml2::XMLElement *element) {
	return Screen::load(element);
}

void SplashScreen::update(int32_t elapsedTime) {
	Screen::update(elapsedTime);
	m_timeToChange += elapsedTime;
	if (m_timeToChange >= 4000)
	{
		Application::instance().getScreenManager().setScreen("MainMenuScreen");
		m_timeToChange = 0;
	}
}
void SplashScreen::draw() {
	Screen::draw();
}