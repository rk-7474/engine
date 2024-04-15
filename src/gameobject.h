#pragma once
#include <SDL2/SDL.h>
#include "types.h"

class GameObject {
    protected:
        SDL_Texture *texture;
        char* texture_name;
        int id;

        fCoords coords;
        SDL_Rect rect;
    public:
        GameObject(Size size, fCoords coords, char* texture);

        void setTexture(SDL_Texture* texture);

        void render();
};