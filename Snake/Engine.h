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
	std::string getInput();
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

	int init();
	void mainLoop();

};

