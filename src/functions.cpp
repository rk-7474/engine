#include "functions.h"
#include "deltaTime.h"
#include "game.h"
#include "string"
#include "entitymanager.h"
#include <SDL2/SDL_ttf.h>

// #define len(type) ((char *)(&type+1)-(char*)(&type))
#define len(arr) (sizeof(arr) / sizeof(arr[0]))

// void DrawText(SDL_Renderer** renderer, char* text) {
// 	TTF_Font* Sans = TTF_OpenFont("Sans.ttf", 24);

// 	SDL_Color White = {255, 255, 255};

// 	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, text, White); 

// 	SDL_Texture* Message = SDL_CreateTextureFromSurface(*renderer, surfaceMessage);

// 	SDL_Rect Message_rect; 
// 	Message_rect.x = 0;   
// 	Message_rect.y = 0; 
// 	Message_rect.w = 1000;
// 	Message_rect.h = 1000;

//     SDL_RenderCopy(*renderer, Message, NULL, &Message_rect);
// }

int frame_counter = 0;
int start_time = SDL_GetTicks64();
int current_fps = 0;

void DrawFps() {
    frame_counter++;

    if (SDL_GetTicks64() - start_time >= 1000) {
        start_time = SDL_GetTicks64();
        current_fps = frame_counter;
        frame_counter = 0;
    }
}

void DrawText(char* text, int size, iCoords pos) {
    //this opens a font style and sets a size
    TTF_Font* Sans = TTF_OpenFont("resources/arcadeclassic.ttf", 24);

    if (!Sans) {
        printf("Failed to load font: %s\n", TTF_GetError());
    }
    // this is the color in rgb format,
    // maxing out all would give you the color white,
    // and it will be your text's color
    SDL_Color White = {255, 255, 255};

    // as TTF_RenderText_Solid could only be used on
    // SDL_Surface then you have to create the surface first
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

void DrawInfo() {
    char buffer[100];
    snprintf(buffer, 100, "FPS %d", current_fps);
    DrawText(buffer, 32, {0, 0});

    fCoords player_pos = EntityManager::getPlayer()->getPosition();

    snprintf(buffer, 100, "Coordinate: %f %f", player_pos.x, player_pos.y);
    DrawText(buffer, 32, {0, 32});
}

char* concat(char* first, char* second) {
    using namespace std;

    string total = string(first) + second;

    return (char*)*total.c_str();
}

