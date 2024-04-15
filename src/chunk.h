#pragma once

#include <SDL2/SDL.h>
#include <vector>
#include "types.h"
#include "config.h"

// fCoords relatives;

#pragma once
// extern fCoords relatives; 

class Chunk {
    private:
        int id;

        char Tiles[CHUNK_SIZE][CHUNK_SIZE];

        std::vector<Decor> decors;

        iCoords coords;
        iCoords absolute;
    public:
        Chunk(int x, int y);

        void render();

        void setTile(int x, int y, int id);
        iCoords getPosition();

        int getId();

        void fill(int id);
};
