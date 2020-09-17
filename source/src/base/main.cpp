#include <cstdio>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "../../include/base/game.h"


void sdlInit();
void sdlQuit();

void printVersions();

int main(int argc, char **argv) {
    sdlInit();
	printVersions();

    Game::instance().run();
   
    sdlQuit();
    SDL_Log("SDL Last Error: %s\n", SDL_GetError()); 
}

void sdlInit() {
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    IMG_Init(IMG_INIT_PNG);
}
void sdlQuit() {
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
}

void printVersions() {
	SDL_version compiled;
	SDL_version linked;
	
	SDL_VERSION(&compiled);
	SDL_GetVersion(&linked);
	printf("We compiled against SDL version %d.%d.%d ...\n",
		compiled.major, compiled.minor, compiled.patch);
	printf("But we are linking against SDL version %d.%d.%d.\n",
		linked.major, linked.minor, linked.patch);
}