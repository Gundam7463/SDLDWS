#pragma once 


class VectorInt2D {
public:
    VectorInt2D();
    VectorInt2D(int x, int y);
    
    
    VectorInt2D operator+(const VectorInt2D &v);
    VectorInt2D& operator+=(const VectorInt2D& v);
    
    VectorInt2D& operator*(int scalar);
    
    int getX();
    int getY();
    
    void setX(int x);
    void setY(int y);
    
private:
    int m_x, m_y;
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
