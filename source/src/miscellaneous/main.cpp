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

#include <cstdio>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "../../include/miscellaneous/game.h"


void sdlInit();
void sdlQuit();

void printVersions();

int main(int argc, char **argv) {
	//SDL_LOG_PRIORITY_INFO
	//SDL_LOG_PRIORITY_WARN
	//SDL_LOG_PRIORITY_CRITICAL
	SDL_LogSetAllPriority(SDL_LOG_PRIORITY_INFO);
	
    sdlInit();
	printVersions();

    Game::instance().run();
   
    sdlQuit();
    SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, "SDL Last Error: %s\n", SDL_GetError()); 
}

void sdlInit() {
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK);
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
	
	SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "We compiled against SDL version %d.%d.%d ...\n",
		compiled.major, compiled.minor, compiled.patch);
	SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "But we are linking against SDL version %d.%d.%d.\n",
		linked.major, linked.minor, linked.patch);
}