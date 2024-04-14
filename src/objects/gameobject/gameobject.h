#pragma once
#include <SDL2/SDL.h>
#include "../../../headers/types.h"

class GameObject {
    protected:
        SDL_Texture *texture;
        char* texture_name;
        int id;

        Coords coords;
        SDL_Rect rect;
    public:
        GameObject(Size size, Coords coords, char* texture);

        void setTexture(SDL_Texture* texture);

        void render();
};