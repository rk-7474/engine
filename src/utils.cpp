#include "utils.h"
#include "time.h"
#include "stdlib.h"
#include "file.h"

int Utils::random(int min, int max) {
    return (rand() % max - min) + min;
}

SDL_Texture* Utils::getRandomDecor() {
    return decors_textures.at(random(0, decors_textures.size()));
}

void Utils::getDecors() {
    printf("Loading decors...\n");
    loadDecors(decors_textures);
}

