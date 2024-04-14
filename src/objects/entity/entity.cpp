#include "entity.h"
#include "../../../headers/deltaTime.h"

void Entity::move(int x, int y) {
    coords.x += x * deltaTime;
    coords.y += y * deltaTime;
} 

Coords Entity::getCoords() {
    return coords;
}

