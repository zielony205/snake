#pragma once
#include "Vec2.h"
#include "Dot.h"
#include "Game.h"
#include <iostream>
#include <SDL.h>


class Engine
{
private:

	SDL_Window *window;
	SDL_Renderer *renderer;


public:

	Game gameManager;
	bool quit;

	Engine();
	~Engine();

	Vec2 getInput();
	int init();
	void clearScreen();
	void renderFrame();
	Vec2 calculateTilePosition(Vec2 pos);
	void drawTile(Vec2 pos);

};


Engine::Engine()
{
	gameManager = Game(Vec2(15, 15), Vec2(0, 1), 30, 30);
	quit = false;
}

int Engine::init()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	window = SDL_CreateWindow("Hello World!", 100, 100, 600, 600, SDL_WINDOW_SHOWN);

	if (window == nullptr)
	{
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (renderer == nullptr) {
		SDL_DestroyWindow(window);
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}
	return 0;
}

Vec2 Engine::getInput()							///////////////TODO
{
	SDL_Event e;
	while (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_QUIT)
		{
			quit = true;
		}
	}
}

void Engine::clearScreen()
{
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer);
}

Vec2 Engine::calculateTilePosition(Vec2 pos)
{
	return Vec2();
}

void Engine::drawTile(Vec2 pos)
{
	SDL_Rect fillRect = { 600 / 4, 600 / 4, 600 / 2, 600 / 2 };
	SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
	SDL_RenderFillRect(renderer, &fillRect);
}



//###################################################################

