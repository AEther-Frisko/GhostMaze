#include <iostream>
#include <SDL3/SDL.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main() {
	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;

	if (!SDL_Init(SDL_INIT_VIDEO)) {
		std::cerr << "SDL failed to initalize! SDL_Error: " << SDL_GetError() << std::endl;
	}
	else {
		window = SDL_CreateWindow("SDL Testing", SCREEN_WIDTH, SCREEN_HEIGHT, 0);
		if (window == NULL) {
			std::cerr << "Window failed to create! SDL_Error: " << SDL_GetError() << std::endl;
		}
		else {
			screenSurface = SDL_GetWindowSurface(window);
			SDL_FillSurfaceRect(screenSurface, NULL, SDL_MapSurfaceRGB(screenSurface, 0xFF, 0xFF, 0xFF));
			SDL_UpdateWindowSurface(window);

			SDL_Event e;
			bool quit = false;
			while (quit == false) {
				while (SDL_PollEvent(&e)) {
					if (e.type == SDL_EVENT_QUIT) {
						quit = true;
					}
				}
			}
		}
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}