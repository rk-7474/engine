#pragma once

#include <SDL2/SDL.h>
#include <vector>
#include "../../headers/types.h"
#include "../../config.h"

// Coords relatives;

#pragma once
// extern Coords relatives; 

class Chunk {
    private:
        int id;

        char Tiles[CHUNK_SIZE][CHUNK_SIZE];

        std::vector<Decor> decors;

        IntCoords coords;
        IntCoords absolute;
    public:
        Chunk(int x, int y);

        void render();

        void setTile(int x, int y, int id);
        IntCoords getPosition();

        int getId();

        void fill(int id);
};
