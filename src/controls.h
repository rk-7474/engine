#pragma once

#include <SDL2/SDL.h>

class Controls {
    public:
        inline static const Uint8* keyboard = NULL;
        static void update();
        static bool isPressed(Uint8 key);
};

