#pragma once
#include "Vec2.h"
#include "Dot.h"
#include "Game.h"
#include <iostream>
#include <SDL.h>
#undef main


class Engine
{
private:

	SDL_Window *window;
	SDL_Renderer *renderer;


public:

	int mapsizeX, mapsizeY, s_width, s_height;

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
	mapsizeX = 30;
	mapsizeY = 30;
	s_width = 600;
	s_height = 600;
	gameManager = Game(Vec2(15, 15), Vec2(0, 1), mapsizeX, mapsizeY);
	quit = false;
	window = NULL;
	renderer = NULL;
}

Engine::~Engine()
{

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
		else if (e.type == SDL_KEYDOWN)
		{
			if (e.key.type == SDLK_UP)
				return Vec2(0, 1);
		}
	}
	return Vec2();
}


void Engine::clearScreen()
{
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderClear(renderer);
}

Vec2 Engine::calculateTilePosition(Vec2 pos)
{
	return Vec2(20 * (pos.x - 1), s_height - 20 * pos.y);
}

void Engine::drawTile(Vec2 pos)
{
	Vec2 position = calculateTilePosition(pos);

	SDL_Rect fillRectBG = { position.x, position.y, 20, 20};
	SDL_SetRenderDrawColor(renderer, 0xBF, 0xC1, 0x24, 0xFF);
	SDL_RenderFillRect(renderer, &fillRectBG);
	SDL_Rect fillRect = { position.x + 2, position.y + 2, 16, 16};
	SDL_SetRenderDrawColor(renderer, 0x2D, 0x77, 0x21, 0xFF);
	SDL_RenderFillRect(renderer, &fillRect);
}

void Engine::renderFrame()
{
	SDL_RenderPresent(renderer);
}
