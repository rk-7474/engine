#include "chunk.h"
#include "../texture/texture.h"
#include "../world/world.h"
#include "../utils/utils.h"
#include "../app/app.h"

int ids = 0;

Chunk::Chunk(int x, int y) {
    id = ids++;

    coords = {x, y};
    absolute = {x * CHUNK_SIZE * TILE_SIZE, x * CHUNK_SIZE * TILE_SIZE};

    // int i, decors_num;

    // decors_num = Utils::random(MIN_DECORS, MAX_DECORS);

    // for (i = 0; i < decors_num; i++) {
    //     Decor decor = {
    //         Utils::random(0, CHUNK_SIZE * TILE_SIZE),
    //         Utils::random(0, CHUNK_SIZE * TILE_SIZE),
    //         Utils::getRandomDecor()
    //     };
    //     decors.push_back(decor);
    // }

    // printf("Decors loaded: %d\n", i, decors_num, MIN_DECORS);

    World::load(this);
}

int Chunk::getId() {
    return id;
}

void Chunk::setTile(int x, int y, int id) {
    Tiles[x][y] = id;
}


void Chunk::render() {
    // printf("Rendering: %d, %d\n", coords.x, coords.y);
    SDL_Rect rect = {0, 0, TILE_SIZE, TILE_SIZE};

    for ( int x = 0; x < CHUNK_SIZE; x++ ) {
        for ( int y = 0; y < CHUNK_SIZE; y++ ) {

            rect.x = absolute.x + x * TILE_SIZE;
            rect.y = absolute.y + y * TILE_SIZE;

            int texture_id = Tiles[x][y] || 0;
            
            SDL_RenderCopy(App::renderer, World::getTexture(texture_id), NULL, &rect);
        }
    }

    // rect = {0, 0, DECOR_SIZE, DECOR_SIZE};
    
    // for ( int i = 0; i < decors.size(); i++ ) {
    //     Decor decor = decors.at(i);
    //     rect.x = absolute.x + decor.x;
    //     rect.y = absolute.y + decor.y;
        
    //     SDL_RenderCopy(App::renderer, decor.texture, NULL, &rect);
    // }
}


void Chunk::fill(int id) {
    for ( int x = 0; x < CHUNK_SIZE; x++ ) {
        for ( int y = 0; y < CHUNK_SIZE; y++ ) {
            this->setTile(x, y, id);
        }
    }
}

IntCoords Chunk::getPosition() {
    return this->coords;
}