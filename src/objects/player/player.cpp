#include "player.h"
#include "../../controls/controls.h"

void Player::update() {
    char* cur_texture;

    if (Controls::isPressed(SDL_SCANCODE_UP)) {
        move(0, -200);
        sprite.setState("move_up");
    }
    if (Controls::isPressed(SDL_SCANCODE_DOWN)) {
        move(0, 200);
        sprite.setState("move_down");
    }
    if (Controls::isPressed(SDL_SCANCODE_RIGHT)) {
        move(200, 0);
        sprite.setState("move_right");
    }
    if (Controls::isPressed(SDL_SCANCODE_LEFT)) {
        move(-200, 0);
        sprite.setState("move_left");
    }

    state state = sprite.getState();
    setTexture(state.texture);
    render();
}