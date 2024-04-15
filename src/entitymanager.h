#pragma once

#include <vector>
#include "chunk.h"
#include "entity.h"
#include "player.h"

class EntityManager {
    private: 
        inline static std::vector<Entity*> entities = {};
        static Player* player;
    public:
        static Entity* spawn(EntityType type, EntityInfo info);
        static Player* getPlayer();
        static void init();
};
