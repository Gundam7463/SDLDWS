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

#include "../../include/miscellaneous/vector_2d.h"


VectorInt2D::VectorInt2D() : m_x(0), m_y(0) { }
VectorInt2D::VectorInt2D(int32_t x, int32_t y) : m_x(x), m_y(y) { }

VectorInt2D VectorInt2D::operator+(const VectorInt2D &v) {
    m_x += v.m_x;
    m_y += v.m_y;
    
    return *this;
}
VectorInt2D& VectorInt2D::operator+=(const VectorInt2D& v) {
    m_x += v.m_x;
    m_y += v.m_y;
    
    return *this;
}

VectorInt2D& VectorInt2D::operator*(int32_t scalar) {
    m_x *= scalar;
    m_y *= scalar;
    
    return *this;
}

int32_t VectorInt2D::getX() { return m_x; }
int32_t VectorInt2D::getY() { return m_y; }

void VectorInt2D::setX(int32_t x) { m_x = x; }
void VectorInt2D::setY(int32_t y) { m_y = y; }


//================================== VectorFloat2D =======================================

VectorFloat2D::VectorFloat2D() : m_x(0.f), m_y(0.f) { }
VectorFloat2D::VectorFloat2D(float x, float y) : m_x(x), m_y(y) { }

VectorFloat2D VectorFloat2D::operator+(const VectorFloat2D &v) {
    m_x += v.m_x;
    m_y += v.m_y;
    
    return *this;
}
VectorFloat2D& VectorFloat2D::operator+=(const VectorFloat2D& v) {
    m_x += v.m_x;
    m_y += v.m_y;
    
    return *this;
}

VectorFloat2D& VectorFloat2D::operator*(float scalar) {
    m_x *= scalar;
    m_y *= scalar;
    
    return *this;
}

float VectorFloat2D::getX() { return m_x; }
float VectorFloat2D::getY() { return m_y; }

void VectorFloat2D::setX(float x) { m_x = x; }
void VectorFloat2D::setY(float y) { m_y = y; }
