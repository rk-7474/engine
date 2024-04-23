#pragma once

#include "types.h"
#include "entity.h"
#include "config.h"

class Entity;

class Player : public Entity {
    public:
        Player(Size size, fCoords coords) : Entity("ENTITY_PLAYER", size, coords) {};

        void move(int x, int y);
        
        void render();

        void update();
};
