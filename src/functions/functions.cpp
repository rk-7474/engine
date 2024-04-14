#include "functions.h"
#include "../../headers/deltaTime.h"
#include "../app/game/game.h"
#include "string"
// #include <SDL2/SDL_ttf.h>

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
char* fps_text = "Ciao!";

void DrawFps() {
    frame_counter++;

    if (SDL_GetTicks64() - start_time >= 1000) {
        // fps_text = concat("FPS: ", (char*)frame_counter);

        printf("FPS: %d\n", frame_counter);
        start_time = SDL_GetTicks64();
        frame_counter = 0;
    }

    // printf("FPS: %s\n", fps_text);

    // DrawText(renderer, fps_text);
}


char* concat(char* first, char* second) {
    using namespace std;

    string total = string(first) + second;

    return (char*)*total.c_str();
}

