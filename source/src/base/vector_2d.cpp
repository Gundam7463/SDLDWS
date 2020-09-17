#include "../../include/base/vector_2d.h"


VectorInt2D::VectorInt2D() : m_x(0), m_y(0) { }
VectorInt2D::VectorInt2D(int x, int y) : m_x(x), m_y(y) { }

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

VectorInt2D& VectorInt2D::operator*(int scalar) {
    m_x *= scalar;
    m_y *= scalar;
    
    return *this;
}

int VectorInt2D::getX() { return m_x; }
int VectorInt2D::getY() { return m_y; }

void VectorInt2D::setX(int x) { m_x = x; }
void VectorInt2D::setY(int y) { m_y = y; }




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
