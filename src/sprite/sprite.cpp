#include "sprite.h"
#include "../texture/texture.h"

void Sprite::addState(char* name, char* texture_path) {
    SDL_Texture* texture = loadTexture(texture_path);
    printf("Texture %s added (%d)\n", name, texture);

    std::string str_name(name);

    bool first = states.empty();
    states[str_name] = texture;

    if (first) setState(name);
    
}

void Sprite::setState(char* name) {
    std::string str_name(name);

    current_state = {name, states[str_name]};
}

state Sprite::getState() {
    return current_state;
}