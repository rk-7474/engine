#include "game.h"
#include "chunk.h"
#include "world.h"
#include "file.h"
#include "utils.h"
#include "entitymanager.h"
#include "config.h"

void App::start() {
    loadTiles();
    // Utils::getDecors();
    EntityManager::init();

    // Chunk* chunk = new Chunk(0, 0);
    // chunk->fill(0);
}

void App::tick() {
    World::update();
    Controls::update();
    // EntityManager::update();
    player->update();
    // player->setTexture(cur_texture);

    // fCoords coords = Player->getPosition();

    // printf("Player coords: %d, %d\n", coords.x, coords.y);
    // RenderChunks();
}

void App::close() {

}