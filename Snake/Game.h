#pragma once

#include "Vec2.h"
#include "Dot.h"
#include "Snake.h"

class Game
{
private:

	typedef enum { RUNNING, STOPPED_PAUSE, STOPPED_DEAD} state;
	state gameState;

	void calculateDotSize();

public:

	int screenWidth;
	int screenHeight;

	int mapX;
	int mapY;

	int initialSnakeLength;
	int score;

	Snake player;
	Dot food;

	Game(int sWidth, int sHeight);

	void generateMap(int sWidth, int sHeight);
	
	void spawnFood();
	void spawnSnake(Vec2 pos, Vec2 dir);
	void checkCollisions();
	bool oobCheck();
	void update();

};

Game::Game(int sWidth, int sHeight)
{
	screenWidth = sWidth;
	screenHeight = sHeight;

	initialSnakeLength = 3;
	gameState = RUNNING;
}

void Game::spawnFood()								///////////////////////////TODO
{

}

void Game::spawnSnake(Vec2 pos, Vec2 dir)
{
	player = Snake(pos, dir, initialSnakeLength);
}

void Game::checkCollisions()
{

}



