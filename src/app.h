#pragma once
#include <SDL2/SDL.h>
#include "types.h"
#include "functions.h"
#include "deltaTime.h"

class App {
    public:
        inline static SDL_Window* window = NULL;
        inline static SDL_Surface* surface = NULL;
        inline static SDL_Renderer* renderer = NULL;
        inline static bool alive = true;

        App();
        ~App();

        void run();
        void start();
        void tick();
        void loop(SDL_Event *e);
        void close();
        
        struct Window {
            static void create(const char* window_name);
            static void destroy();
        };
};