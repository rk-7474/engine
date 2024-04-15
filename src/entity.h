#pragma once

#include "types.h"
#include "gameobject.h"
#include "sprite.h"

typedef char* EntityType;

typedef struct {
    fCoords coords;
    Size size;
} EntityInfo;

class Entity : public GameObject {
    protected:
        int health;
        int maxHealth;
        EntityType type;
    public:
        Sprite sprite;
        
        Entity(EntityType type, Size size, fCoords coords) : GameObject(size, coords, NULL) {
            this->type = type;
        };

        void move(int x, int y);
        void update();

        fCoords getPosition();
};

