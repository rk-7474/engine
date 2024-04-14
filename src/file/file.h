#pragma once

#include <iostream>
#include <vector>
#include <SDL2/SDL_image.h>

namespace File {
    std::vector<char*> read(char* fileName);
}

void loadTiles();

void loadDecors(std::vector<SDL_Texture*>& textures);
