#include "texture.h"
#include <SDL2/SDL_image.h>
#include "../app/app.h"
#include <stdio.h>
#include <map>

std::map<char*, SDL_Texture*> loaded_textures;

SDL_Texture* loadTexture(char* texture_name) {
    if (loaded_textures.find(texture_name) != loaded_textures.end())
        return loaded_textures[texture_name];

    SDL_Texture* texture = IMG_LoadTexture(App::renderer, texture_name);

    if (texture == NULL) {
        printf("Error loading texture \"%s\"!\nError: %s\n", texture_name, SDL_GetError());
        return NULL;
    }

    loaded_textures[texture_name] = texture;

    return texture;
}


bool unloadTexture(char* texture_name) {
    
    if (loaded_textures.find(texture_name) == loaded_textures.end()) {
        printf("Error unloading texture: texture \"%s\" not found", texture_name);
        return false;
    }

    delete loaded_textures[texture_name];
    return true;
}