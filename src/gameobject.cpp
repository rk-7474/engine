#include "gameobject.h"
#include "texture.h"
#include "app.h"

static int id = 0;

GameObject::GameObject(Size size, fCoords coords, char* texture) {
    this->id = id++;
    if (texture != NULL) 
        this->texture = loadTexture(texture);

    rect.w = size.w;
    rect.h = size.h;

    rect.x = coords.x;
    rect.y = coords.y;

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