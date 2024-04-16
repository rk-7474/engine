#pragma once

#include <vector>
#include "entity.h"
#include "player.h"

class EntityManager {
    private: 
        inline static std::vector<Entity*> entities = {};
        inline static Player* player = NULL;
    public:
        static Entity* spawn(EntityType type, EntityInfo info);
        static Player* getPlayer();
        static void init();
};
