#include "map_generator.h"

void GenerateCircleMap(SDL_Renderer *renderer, int circleRadius) {
    for (int i = -circleRadius; i < circleRadius; i++) {
        (new Chunk(renderer, i, 0))->FullFill(0);
        if (i != 0) (new Chunk(renderer, 0, i))->FullFill(0);
    }
}

void GenerateSquareMap(SDL_Renderer *renderer, int squareSide) {
    for (int i = -(squareSide/2); i < squareSide; i++)
        for (int j = -(squareSide/2); j < squareSide; j++)
            (new Chunk(renderer, i, j))->FullFill(1);
}
