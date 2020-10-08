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

#pragma once 

#include <cstdint>


class VectorInt2D {
public:
    VectorInt2D();
    VectorInt2D(int32_t x, int32_t y);
    
    
    VectorInt2D operator+(const VectorInt2D &v);
    VectorInt2D& operator+=(const VectorInt2D& v);
    
    VectorInt2D& operator*(int32_t scalar);
    
    int32_t getX();
    int32_t getY();
    
    void setX(int32_t x);
    void setY(int32_t y);
    
private:
    int32_t m_x, m_y;
};

class VectorFloat2D {
public:
    VectorFloat2D();
    VectorFloat2D(float x, float y);
    
    
    VectorFloat2D operator+(const VectorFloat2D& v);
    VectorFloat2D& operator+=(const VectorFloat2D& v);
    
    VectorFloat2D& operator*(float scalar);
    
    float getX();
    float getY();
    
    void setX(float x);
    void setY(float y);
    
private:
    float m_x, m_y;
};
