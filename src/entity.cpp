#include "entity.h"
#include "deltaTime.h"

void Entity::move(int x, int y) {
    coords.x += x * deltaTime;
    coords.y += y * deltaTime;
} 

fCoords Entity::getPosition() {
    return coords;
}

