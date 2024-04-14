#include "gameobject.h"
#include "../../texture/texture.h"
#include "../../app/app.h"

static int id = 0;

GameObject::GameObject(Size size, Coords coords, char* texture) {
    this->id = id++;
    if (texture != NULL) 
        this->texture = loadTexture(texture);

    rect.w = size.w;
    rect.h = size.h;

    this->coords = coords;
}

void GameObject::render() {
    rect.x = (int)coords.x;
    rect.y = (int)coords.y;
    // printf("Texure addr: %d\n", texture);
    SDL_RenderCopy(App::renderer, texture, NULL, &rect);
}

void GameObject::setTexture(SDL_Texture* texture) {
    this->texture = texture; 
}