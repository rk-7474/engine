#include "controls.h"

void Controls::update() {
    SDL_PumpEvents();
    keyboard = SDL_GetKeyboardState(NULL);
}

bool Controls::isPressed(Uint8 key) {
    return keyboard[key];
}