#include "player.h"
#include "controls.h"
#include "camera.h"
#include "deltaTime.h"
#include "app.h"

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

void Player::move(int x, int y) {
    coords.x += x * deltaTime;
    coords.y += y * deltaTime;

    Camera::setPosition(coords);
}

void Player::render() {
    SDL_RenderCopy(App::renderer, texture, NULL, &rect);
}
