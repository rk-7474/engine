#pragma once

#include "types.h"
#include "entity.h"

class Entity;

class Player : public Entity {
    public:
        Player(Size size, fCoords coords) : Entity("ENTITY_PLAYER", size, coords) {
            this->coords = {0.0f, 0.0f};
        };

        void move(int x, int y);
        void render();

        void update();
};
