#include "world.h"
#include "../texture/texture.h"

void World::render() {
    for (int i = 0; i < rendered.size(); i++) {
        rendered.at(i)->render();
    }
}

void World::load(Chunk* chunk) {
    rendered.push_back(chunk);
}

void World::unload(int id) {
    for (int i = 1; i < rendered.size(); i++)
        if (rendered.at(i)->getId() == id) {
            delete rendered.at(i);
            rendered.erase(rendered.begin() + i);
            return;
        }
}

void World::registerTile(char* texture) {
    tiles_textures.push_back(loadTexture(texture));
}
SDL_Texture* World::getTexture(int id) {
    return tiles_textures.at(id);
}
