#pragma once
#include "Vec2.h"
#include "Dot.h"
#include "Game.h"
#include <iostream>


class Engine
{
public:

	Game gameManager;

	Engine();
	~Engine();

	Vec2 getInput();
	void renderFrame();

};


Engine::Engine()
{
	gameManager = Game(Vec2(15, 15), Vec2(0, 1), 30, 30);

}

Vec2 Engine::getInput()
{

}
