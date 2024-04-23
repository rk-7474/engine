#include "app.h"
#include "drawtext.h"

void Text::Draw(char* text, int size, iCoords pos) {
    if (!Sans) {
        printf("Failed to load font: %s\n", TTF_GetError());
    }

    SDL_Surface* surfaceMessage =
        TTF_RenderText_Solid(Sans, text, White); 

    if (surfaceMessage == NULL) printf("Surface is null\n");

    // now you can convert it into a texture
    SDL_Texture* Message = SDL_CreateTextureFromSurface(App::renderer, surfaceMessage);

    if (Message == NULL) printf("Message is null\n");

    SDL_Rect Message_rect; //create a rect
    Message_rect.x = pos.x;  //controls the rect's x coordinate 
    Message_rect.y = pos.y; // controls the rect's y coordinte
    Message_rect.w = size * strlen(text) / 2; // controls the width of the rect
    Message_rect.h = size; // controls the height of the rect

    // (0,0) is on the top left of the window/screen,
    // think a rect as the text's box,
    // that way it would be very simple to understand

    // Now since it's a texture, you have to put RenderCopy
    // in your game loop area, the area where the whole code executes

    // you put the renderer's name first, the Message,
    // the crop size (you can ignore this if you don't want
    // to dabble with cropping), and the rect which is the size
    // and coordinate of your texture
    SDL_RenderCopy(App::renderer, Message, NULL, &Message_rect);
}

void Text::Init() {
    TTF_Init();
    Sans = TTF_OpenFont("resources/arcadeclassic.ttf", 36);
}