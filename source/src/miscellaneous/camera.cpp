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

#include "../../include/miscellaneous/camera.h"
#include "../../include/miscellaneous/graphics.h"

Camera::Camera() {
}
void Camera::init(uint32_t maxWidth, uint32_t maxHeight) {
	m_position = VectorFloat2D();
	m_size = VectorInt2D(maxWidth, maxHeight);
}
void Camera::moveHorizontal(float speed) {
	
	m_position.setX(m_position.getX() + speed);
}
void Camera::moveVertical(float speed) {

	m_position.setY(m_position.getY() + speed);
}
SDL_Rect Camera::getViewportRect() {
	const SDL_Rect viewport = { (int)m_position.getX(), (int)m_position.getY(),
	m_size.getX(), m_size.getY() };
	
	return viewport;
}
void Camera::updateViewport() {
	SDL_Rect viewport = getViewportRect();
	
	Graphics::instance().setViewport(&viewport);
}
