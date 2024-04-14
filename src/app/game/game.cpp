#include "game.h"
#include "../../chunk/chunk.h"
#include "../../world/world.h"
#include "../../file/file.h"
#include "../../utils/utils.h"

void App::start() {
    loadTiles();
    // Utils::getDecors();
    player = new Player({64, 82}, {0, 0});
    player->sprite.addState("move_down",  "textures/player/front.png");
    player->sprite.addState("move_up",    "textures/player/back.png");
    player->sprite.addState("move_right", "textures/player/right.png");
    player->sprite.addState("move_left",  "textures/player/left.png");
    Chunk* chunk = new Chunk(0, 0);
    chunk->fill(0);
}

void App::tick() {
    World::render();
    Controls::update();
    player->update();
    // player->setTexture(cur_texture);

    // Coords coords = Player->getCoords();

    // printf("Player coords: %d, %d\n", coords.x, coords.y);
    // RenderChunks();
}

void App::close() {

}