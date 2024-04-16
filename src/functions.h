#pragma once

#include <SDL2/SDL.h>

// void DrawText(SDL_Renderer** renderer, char* text);

void DrawFps();

void DrawText(char* text, int size);
char* concat(char* first, char* second);
void DrawInfo();

// int len(char* array[]);