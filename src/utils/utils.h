#pragma once

#include <SDL2/SDL_image.h>
#include <vector>
#include "../../headers/types.h"

namespace Utils {
    int random(int min, int max);

    inline std::vector<SDL_Texture*> decors_textures = {};

    SDL_Texture* getRandomDecor();

    void getDecors();
}