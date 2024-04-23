#include "game.h"
#include "world.h"
#include "file.h"
#include "utils.h"
#include "entitymanager.h"
#include "config.h"
#include "functions.h"
#include "camera.h"
#include "drawtext.h"
#include <time.h>
#include <stdlib.h>

void App::start() {
    srand(time(NULL));
    EntityManager::init();
    Text::Init();
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
    DrawInfo();
    
    // player->setTexture(cur_texture);

    // RenderChunks();
}

void App::close() {

}