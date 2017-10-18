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

	Uint64 time_now;
	Uint64 time_last;
	double deltaTime;

	void calculateDeltaTime();
	Vec2 getInput();
	void clearScreen();
	Vec2 calculateTilePosition(Vec2 pos);
	void drawTile(Vec2 pos);
	void preRenderUpdate();
	void renderFrame();

public:

	int mapsizeX, mapsizeY, s_width, s_height;
	Game gameManager;
	bool quit;

	Engine();
	~Engine();

	int init();
	void mainLoop();

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

	window = SDL_CreateWindow("Snake!", 100, 100, 600, 600, SDL_WINDOW_SHOWN);

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

	time_now = SDL_GetPerformanceCounter();
	time_last = 0;
	deltaTime = 0;

	return 0;
}


void Engine::calculateDeltaTime()
{
	time_last = time_now;
	time_now = SDL_GetPerformanceCounter();

	deltaTime = (double)((time_now - time_last) * 1000 / SDL_GetPerformanceFrequency());

	//std::cout << deltaTime << std::endl;
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
			switch (e.key.keysym.sym)
			{
			case SDLK_UP:
				return Vec2(0, 1);
			case SDLK_DOWN:
				return Vec2(0, -1);
			case SDLK_LEFT:
				return Vec2(-1, 0);
			case SDLK_RIGHT:
				return Vec2(1, 0);
			}
		}
	}
	return Vec2(0, 0);
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

	SDL_Rect fillRectBG = { position.x + 1, position.y + 1, 18, 18};
	SDL_SetRenderDrawColor(renderer, 0xBF, 0xC1, 0x24, 0xFF);
	SDL_RenderFillRect(renderer, &fillRectBG);
	SDL_Rect fillRect = { position.x + 3, position.y + 3, 14, 14};
	SDL_SetRenderDrawColor(renderer, 0x2D, 0x77, 0x21, 0xFF);
	SDL_RenderFillRect(renderer, &fillRect);
}

void Engine::preRenderUpdate()
{
	clearScreen();
	std::vector<Dot> tiles = gameManager.dotsToRender();
	for (unsigned int i = 0; i < tiles.size(); ++i)
	{
		drawTile(tiles.at(i).pos);
	}
}

void Engine::renderFrame()
{
	SDL_RenderPresent(renderer);
}

void Engine::mainLoop()
{
	calculateDeltaTime();
	if (gameManager.update(getInput(), deltaTime))
	{
		preRenderUpdate();
		renderFrame();
	}
}
