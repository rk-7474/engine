#pragma once

#include "../../../headers/types.h"
#include "../gameobject/gameobject.h"
#include "../../sprite/sprite.h"

class Entity : public GameObject {
    protected:
        int health;
        int maxHealth;
    public:
        Sprite sprite;
        
        Entity(Size size, Coords coords) : GameObject(size, coords, NULL) {};

        void move(int x, int y);
        void update();

        Coords getCoords();
};

