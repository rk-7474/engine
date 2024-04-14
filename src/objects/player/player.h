#pragma once

#include "../../../headers/types.h"
#include "../entity/entity.h"

class Entity;

class Player : public Entity {
    public:
        Player(Size size, Coords coords) : Entity(size, coords) {};

        void update();
};
