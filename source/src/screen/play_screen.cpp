#include "../../include/screen/play_screen.h"

void PlayScreen::unload() {
	Screen::unload();
}
bool PlayScreen::load(tinyxml2::XMLElement *element) {
	return Screen::load(element);
}

void PlayScreen::update(int elapsedTime) {
	Screen::update(elapsedTime);
}
void PlayScreen::draw() {
	Screen::draw();
}