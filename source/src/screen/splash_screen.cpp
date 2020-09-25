#include "../../include/screen/splash_screen.h"

void SplashScreen::unload() {
	Screen::unload();
}
bool SplashScreen::load(tinyxml2::XMLElement *element) {
	return Screen::load(element);
}

void SplashScreen::update(int elapsedTime) {
	Screen::update(elapsedTime);
}
void SplashScreen::draw() {
	Screen::draw();
}