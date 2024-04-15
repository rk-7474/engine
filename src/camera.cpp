#include "camera.h"
#include "deltaTime.h"

void Camera::move(int x, int y) {
    absolute.x += -x * deltaTime;
    absolute.y += -y * deltaTime;
}

void Camera::setPosition(fCoords coords) {
    absolute = coords;
}

fCoords Camera::getPosition() {
    return absolute;    
}