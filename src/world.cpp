#include "world.h"
#include "texture.h"
#include "player.h"
#include "entitymanager.h"

static iCoords last_player_chunk_coords;

void World::update() {
    render();   

    iCoords current_player_chunk_coords = getPlayerChunkPosition();

    if (last_player_chunk_coords.x != current_player_chunk_coords.x || last_player_chunk_coords.y != current_player_chunk_coords.y) {
        reload();        
    }

    last_player_chunk_coords = current_player_chunk_coords;
}

Chunk* World::getCurrent() {
    iCoords player_chunk_coords = getPlayerChunkPosition();

    for (int i = 0; i < rendered.size(); i++) {
        iCoords current_chunk_coords = rendered.at(i)->getPosition();
        if (current_chunk_coords.x == player_chunk_coords.x && current_chunk_coords.y == player_chunk_coords.y) {
            return rendered.at(i);
        }
    }
}

iCoords World::getPlayerChunkPosition() {
    fCoords player_coords = EntityManager::getPlayer()->getPosition();
    
    iCoords player_chunk_coords = {
        player_coords.x / (CHUNK_SIZE * TILE_SIZE),
        player_coords.y / (CHUNK_SIZE * TILE_SIZE),
    };

    return player_chunk_coords;
}

void World::render() {
    for (int i = 0; i < rendered.size(); i++) {
        rendered.at(i)->render();
    }
}

void World::load(Chunk* chunk) {
    rendered.push_back(chunk);
}

void World::unload(int id) {
    for (int i = 0; i < rendered.size(); i++)
        if (rendered.at(i)->getId() == id) {
            delete rendered.at(i);
            rendered.erase(rendered.begin() + i);
            return;
        }
}

void World::create(int x, int y) {
    loadFromMemory(x, y);
}

void World::loadFromMemory(int x, int y) {
    Chunk* new_chunk = new Chunk(x, y);
    new_chunk->fill(0);
    load(new_chunk);
}

void World::reload() {
    // Chunk* center = getCurrentChunk(); 
    iCoords center = getPlayerChunkPosition();

    printf("reloading chunks");

    rendered = {};

    create(center.x, center.y);

    for (int i = 1; i < RENDER_DISTANCE; i++) {
        create(center.x - i, center.y);
        create(center.x + i, center.y);
        create(center.x, center.y + i);
        create(center.x, center.y - i);
    
        if (i > 1) {
            int j = i-1;
            create(center.x + j, center.y + j);
            create(center.x + j, center.y - j);
            create(center.x - j, center.y + j);
            create(center.x - j, center.y - j);
        }
    }
}   

void World::registerTile(char* texture) {
    tiles_textures.push_back(loadTexture(texture));
}
SDL_Texture* World::getTexture(int id) {
    return tiles_textures.at(id);
}
