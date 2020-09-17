#include "../../include/entity/background.h"



bool Background::load(const Loader* loader) {
	return Sprite::load(loader);
}
void Background::unload() {
	Sprite::unload();
}

void Background::update(int elapsedTime) {
	Sprite::update(elapsedTime);
}
void Background::draw() {
	Sprite::draw();
}