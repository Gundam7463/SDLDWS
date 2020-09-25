#include "../../include/screen/main_menu_screen.h"


void MainMenuScreen::unload() {
	Screen::unload();
}
bool MainMenuScreen::load(tinyxml2::XMLElement *element) {
	return Screen::load(element);
}

void MainMenuScreen::update(int elapsedTime) {
	Screen::update(elapsedTime);
}
void MainMenuScreen::draw() {
	Screen::draw();
}