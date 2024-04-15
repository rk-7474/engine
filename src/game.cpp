#include "game.h"
#include "chunk.h"
#include "world.h"
#include "file.h"
#include "utils.h"
#include "entitymanager.h"
#include "config.h"
#include "camera.h"

void App::start() {
    EntityManager::init();

    loadTiles();
    // Utils::getDecors();

    // Chunk* chunk = new Chunk(0, 0);
    // chunk->fill(0);
}

void App::tick() {
    World::update();
    Controls::update();
    // EntityManager::update();
    EntityManager::getPlayer()->update();
    // player->setTexture(cur_texture);

    // RenderChunks();
}

void App::close() {

}