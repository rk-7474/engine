#include "app.h"

App::App() {
    Window::create(WINDOW_NAME);
}

App::~App() {
    Window::destroy();
}

void App::run() {
    start();
    
	SDL_Event e;
	while (alive && e.type != SDL_QUIT) loop(&e);

    close();
}

void App::loop(SDL_Event *e) {
    Uint64 start = SDL_GetTicks64();
    SDL_PollEvent( e );
    SDL_RenderClear(renderer);
    DrawFps();
    tick();
    SDL_RenderPresent(renderer);
    SDL_Delay(deltaTime*1000 - (SDL_GetTicks64() - start));
}