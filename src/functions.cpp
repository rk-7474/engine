#include "functions.h"
#include "deltaTime.h"
#include "game.h"
#include "string"
#include "entitymanager.h"
#include "drawtext.h"
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

void DrawInfo() {
    char buffer[100];
    snprintf(buffer, 100, "FPS %d", current_fps);
    Text::Draw(buffer, 32, {0, 0});

    fCoords player_pos = EntityManager::getPlayer()->getPosition();

    snprintf(buffer, 100, "Coordinate: %f %f", player_pos.x, player_pos.y);
    Text::Draw(buffer, 32, {0, 32});
}

char* concat(char* first, char* second) {
    using namespace std;

    string total = string(first) + second;

    return (char*)*total.c_str();
}

