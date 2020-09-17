#include "../../include/base/camera.h"
#include "../../include/base/graphics.h"

Camera::Camera() {
    m_viewport.x = m_viewport.y = 0;
}
void Camera::init() {
    int ww, wh;
    Graphics::instance().getWindowSize(&ww, &wh);
    
    m_viewport.w = ww;
    m_viewport.h = wh;
}
