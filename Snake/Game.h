#pragma once

#include "Vec2.h"
#include "Dot.h"
#include "Snake.h"
#include <stdlib.h>
#include <time.h>

class Game
{
private:

	
public:
	
	typedef enum { RUNNING, STOPPED_PAUSE, STOPPED_DEAD } state;
	state gameState;

	int mapX;
	int mapY;

	int initialSnakeLength;
	int score;

	Snake player;
	Dot food;

	Game(Vec2 snakePos, Vec2 snakeDir);
	
	void spawnFood();
	void spawnSnake(Vec2 pos, Vec2 dir);

	void checkCollisions();
	bool oobCheck();

	void update();

	void handleInput(Vec2 input);
	int randomize(int maxNum);

};



Game::Game(Vec2 snakePos, Vec2 snakeDir)
{
	srand(time(NULL));
	initialSnakeLength = 3;
	gameState = RUNNING;
	spawnSnake(snakePos, snakeDir);
	spawnFood();
}

void Game::spawnFood()
{
	food = Dot(Vec2(randomize(mapX), randomize(mapY)), FOOD);
}

void Game::spawnSnake(Vec2 pos, Vec2 dir)
{
	player = Snake(pos, dir, initialSnakeLength);
}

void Game::checkCollisions()
{
	for (int i = 1; i < player.body.size; ++i)			//Player crashed into his tail
	{
		if (player.headPosition == player.body.at(i).pos)
		{
			gameState = STOPPED_DEAD;
			return;
		}
	}

	if (oobCheck())
	{
		gameState = STOPPED_DEAD;
		return;
	}

	if (player.headPosition == food.pos)				//Player collecting food
	{
		player.grow();
		spawnFood();
	}
}


bool Game::oobCheck()
{
	if (player.headPosition.x < 1 ||
		player.headPosition.x > 30 ||
		player.headPosition.y < 1 ||
		player.headPosition.y > 30)
	{
		return true;
	}
	return false;
}


void Game::handleInput(Vec2 input)
{
	if (input == Vec2(0, 1))
		player.changeDirection(input);
	else if (input == Vec2(0, -1))
		player.changeDirection(input);
	else if (input == Vec2(1, 0))
		player.changeDirection(input);
	else if (input == Vec2(-1, 0))
		player.changeDirection(input);
}

int Game::randomize(int maxNum)
{
	return rand() % maxNum + 1;
}

