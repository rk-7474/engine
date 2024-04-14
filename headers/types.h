#pragma once
#include <SDL2/SDL.h>

typedef struct {
    float x = 0;
    float y = 0;
} Coords;

typedef struct {
    int x = 0;
    int y = 0;
} IntCoords;

typedef struct {
    int w = 0;
    int h = 0;
} Size;

typedef struct {
    int x = 0;
    int y = 0;
    SDL_Texture *texture;
} Decor;