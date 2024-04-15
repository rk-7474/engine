#include "app.h"

void App::Window::create(const char* window_name) {
	if (SDL_Init( SDL_INIT_VIDEO ) < 0) {
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		return;
	}

	window = SDL_CreateWindow(window_name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
	
	if (window == NULL) {
		printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		return;
	}

	renderer = SDL_CreateRenderer(window, -1, 0);
    surface = SDL_GetWindowSurface( window );

	SDL_FillRect( surface, NULL, SDL_MapRGB( surface->format, 0xFF, 0xFF, 0xFF ) );
	
	SDL_UpdateWindowSurface( window );
}

void App::Window::destroy() {
	SDL_DestroyWindow( window );
	SDL_Quit();
}
