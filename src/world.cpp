#include "world.h"
#include "texture.h"
#include "player.h"
#include "entitymanager.h"
#include "camera.h"
#include "app.h"

static iCoords last_tile;

void World::update() {
    render();   

    iCoords current_tile = getCurrent();

    if (last_tile.x != current_tile.x || last_tile.y != current_tile.y) {
        reload();        
    }

    last_tile = current_tile;
}

iCoords World::getCurrent() {
    fCoords player_coords = EntityManager::getPlayer()->getPosition();

    iCoords current_tile = {
        player_coords.x / TILE_SIZE,
        player_coords.y / TILE_SIZE,
    };

    return current_tile;    
}

void World::render() {
    fCoords camera_coords = Camera::getPosition();

    for (auto const& [x, yMap] : tiles) {
        for (auto const& [y, id] : yMap) {
            int tile_x = x * TILE_SIZE - camera_coords.x;
            int tile_y = y * TILE_SIZE - camera_coords.y;

            SDL_Rect rect = {tile_x, tile_y, TILE_SIZE, TILE_SIZE};
            SDL_RenderCopy(App::renderer, World::getTexture(id), NULL, &rect);
        }
    }
}

void World::load(int x, int y, char id) {
    tiles[x][y] = id;
}

void World::unload(int x, int y) {
    tiles[x].erase(y);
    if (tiles[x].empty()) tiles.erase(x);
}

void World::create(int x, int y) {
    generate(x, y, true);
}

void World::loadFromMemory(int x, int y) {
    load(x, y, 1);
}

int World::generate(int x, int y, bool create_neighbors) {
    int id;
    // if (!create_neighbors)
        id = rand() % 2 + 1;
    // else
        // id = getNeighbors(x, y);

    load(x, y, id);
    return id;
}

int World::getNeighbors(int x, int y) {

    std::vector<int> neighbors;

    for (int i = 0; i <= TILES_NUMBER; i++) {
        neighbors.push_back(0);
    }

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;

            int new_x = x + i;
            int new_y = y + j;

            int id;

            if (tiles[new_x][new_y] == NULL || tiles[new_x][new_y] == 0)
                id = generate(new_x, new_y, false);
            else 
                id = tiles[new_x][new_y];
            
            neighbors[id]++;
        } 
    }

    int max_n = 0;
    int max_id = 0;

    for (int i = 1; i < neighbors.size(); i++) {
        if (max_n == 0 || neighbors.at(i) > max_n) {
            max_id = i;
            max_n = neighbors.at(i);
        }
    }

    return max_id;
}


void World::reload() {
    iCoords center = getCurrent();

    tiles.clear();

    for (int x = center.x - RENDER_DISTANCE; x <= center.x + RENDER_DISTANCE; x++)
        for (int y = center.y - RENDER_DISTANCE; y <= center.y + RENDER_DISTANCE; y++)
            create(x, y);
}   

void World::registerTile(char* texture, char id) {
    printf("Loading %s with ID %d\n", texture, id);
    textures[id] = loadTexture(texture);
}
SDL_Texture* World::getTexture(char id) {
    return textures[id];
}

