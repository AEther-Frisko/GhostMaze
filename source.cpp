#include <cmath>
#include <iostream>
#include <SDL3/SDL.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

/*
	Starts up SDL and creates a window.
	Returns the success/fail state of its actions.
*/
bool init() {
	bool success = true;

	if (!SDL_Init(SDL_INIT_VIDEO)) {
		SDL_Log("SDL failed to initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else {
		window = SDL_CreateWindow("Raycaster", SCREEN_WIDTH, SCREEN_HEIGHT, 0);
		if (window == NULL) {
			SDL_Log("Window failed to create! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}
	}

	SDL_Log("SDL initialized successfully.\n");
	return success;
}

/*
	Cleans things up and shuts down SDL.
*/
void close() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	renderer = NULL;
	window = NULL;

	SDL_Quit();
	SDL_Log("Quitting...\n");
}

int main() {
	if (init()) {
		bool quit = false;
		SDL_Event e;
		
		// main running loop
		while (!quit) {
			while (SDL_PollEvent(&e)) {
				if (e.type == SDL_EVENT_QUIT) {
					quit = true;
				}
			}
		}
	}

	close();

	return 0;
}