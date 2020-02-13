#include <iostream>
#include <random>
#include <ctime>
#include "SDL.h"

int main(int argc, char *argv[]) {
	int err = SDL_Init(SDL_INIT_EVERYTHING);
	if (err) {
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	const int height = 640;
	const int width = 480;

	SDL_Window* window = SDL_CreateWindow("Hello World!", 100, 100, height, width, SDL_WINDOW_SHOWN);
	if (!window) {
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	srand(time(nullptr));

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	while (true) {
		int y = rand() % height;
		int x = rand() % width;
		int yy = rand() % height;
		int xx = rand() % width;
		SDL_RenderDrawLine(renderer,x,y,xx,yy);
		SDL_RenderPresent(renderer);
		SDL_Delay(1000);
	}
	return 0;
}