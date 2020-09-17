#include <SDL2/SDL_image.h>
#include "../../include/input/mouse.h"


extern std::string gRootDir;

Mouse::Mouse() {
	m_cursor = 0;
    m_mouseSurface = 0;
}
Mouse::~Mouse() {
	if (m_cursor)
    {
		SDL_FreeCursor(m_cursor);
    }
    m_cursor = 0;
    if (m_mouseSurface)
    {
        SDL_FreeSurface(m_mouseSurface);
    }
}
void Mouse::createCursor(const char *path, int hot_x, int hot_y) {
	if (!m_cursor)
	{
		std::string finalPath = gRootDir;
		finalPath += "/img/";
		finalPath += path;
		
		m_mouseSurface = IMG_Load(finalPath.c_str());
		if (m_mouseSurface)
		{
			if (!(m_cursor = SDL_CreateColorCursor(m_mouseSurface, hot_x, hot_y)))
			{
				SDL_FreeSurface(m_mouseSurface);
				fprintf(stdout, "WARN: Cannot create cursor\n");
			}
			else
			{
				SDL_SetCursor(m_cursor);
			}		
		}
	}
}
void Mouse::clearFrame() {
	m_pressed.clear();
	m_released.clear();
}
void Mouse::updateInput(SDL_Event &ev) {
	if (ev.type == SDL_MOUSEBUTTONDOWN)
	{
		m_pressed[ev.button.button] = true;
		m_released[ev.button.button] = false;
		m_holded[ev.button.button] = true;
	}
	else if (ev.type == SDL_MOUSEBUTTONUP)
	{
		m_pressed[ev.button.button] = false;
		m_released[ev.button.button] = true;
		m_holded[ev.button.button] = false;		
	}
}
bool Mouse::getPressed(int key) {
	return m_pressed[key];
}
bool Mouse::getReleased(int key) {
	return m_released[key];
}
bool Mouse::getHolded(int key) {
	return m_holded[key];
}
void Mouse::getPosition(int *x, int *y) {
	SDL_GetMouseState(x, y);
}
