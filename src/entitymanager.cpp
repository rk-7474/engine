#include "entitymanager.h"

Entity* EntityManager::spawn(EntityType type, EntityInfo info) {
    Entity* new_entity = new Entity(type, info.size, info.coords);
    entities.push_back(new_entity);
}

Player* EntityManager::getPlayer() {
    return player;
}

void EntityManager::init() {
    player = new Player((Size) {PLAYER_WIDTH, PLAYER_HEIGHT}, (fCoords) {(SCREEN_WIDTH-PLAYER_WIDTH)/2, (SCREEN_HEIGHT-PLAYER_HEIGHT)/2});
    player->sprite.addState("move_down",  "textures/player/front.png");
    player->sprite.addState("move_up",    "textures/player/back.png");
    player->sprite.addState("move_right", "textures/player/right.png");
    player->sprite.addState("move_left",  "textures/player/left.png");
}