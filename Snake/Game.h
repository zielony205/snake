#pragma once

#include "Vec2.h"
#include "Dot.h"
#include "Snake.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

class Game
{
private:

	typedef enum { RUNNING, STOPPED_PAUSE, STOPPED_DEAD } state;
	state gameState;
	int playerSpeed, tCounter;
		
public:
	
	int mapX, mapY;
	int initialSnakeLength;
	int score;
	Snake player;
	Dot food;
	Vec2 sPos, sDir;
	bool renderNextFrame;

	Game();
	Game(Vec2 snakePos, Vec2 snakeDir, int mX, int mY);
	
	void init();
	void spawnFood();
	void spawnSnake(Vec2 pos, Vec2 dir);
	void checkCollisions();
	bool oobCheck();
	void handleInput(std::string input);
	int randomize(int maxNum);
	void update(std::string input, double dTime);
	std::vector<Dot> dotsToRender();
};

Game::Game()
{
}

Game::Game(Vec2 snakePos, Vec2 snakeDir, int mX, int mY)	//Constructor
{
	srand(time(NULL));
	initialSnakeLength = 10;
	mapX = mX;
	mapY = mY;
	playerSpeed = 100;
	tCounter = 0;
	sPos = snakePos;
	sDir = snakeDir;
	init();
}

void Game::init()					//Set start values for game objects
{
	spawnSnake(sPos, sDir);
	spawnFood();
	score = 0;
	renderNextFrame = true;
	gameState = RUNNING;
}

void Game::spawnFood()					//Spawns food on random position on map
{
	food = Dot(Vec2(randomize(mapX), randomize(mapY)), FOOD);
}

void Game::spawnSnake(Vec2 pos, Vec2 dir)				//Spawns snake on provided position and with provided direction
{
	player = Snake(pos, dir, initialSnakeLength);
}

void Game::checkCollisions()					//Maintains checking and handling collisions
{
	Vec2 predictedHeadPos = player.headPosition + player.headDirection;

	for (unsigned int i = 1; i < player.body.size(); ++i)			//Player crashed into his tail
	{
		if (player.headPosition == player.body.at(i).pos)
		{
			gameState = STOPPED_DEAD;
			renderNextFrame = false;
			return;
		}
	}

	if (oobCheck())					//Player crashed into wall
	{
		gameState = STOPPED_DEAD;
		renderNextFrame = false;
		return;
	}

	if (player.headPosition == food.pos)			//Player collecting food
	{
		player.grow();
		spawnFood();
		score += 1;
		std::cout << "Score: " << score << std::endl;
	}
}

bool Game::oobCheck()
{
	Vec2 predictedHeadPos = player.headPosition;//+player.headDirection;
	if (predictedHeadPos.x < 1 ||
		predictedHeadPos.x > 30 ||
		predictedHeadPos.y < 1 ||
		predictedHeadPos.y > 30)
	{
		return true;
	}
	return false;
}

void Game::handleInput(std::string input)			//Handle input provided by Engine
{
	if (gameState == RUNNING)
	{
		if (input == "up")
			player.changeDirection(Vec2(0, 1));
		else if (input == "down")
			player.changeDirection(Vec2(0, -1));
		else if (input == "right")
			player.changeDirection(Vec2(1, 0));
		else if (input == "left")
			player.changeDirection(Vec2(-1, 0));
	}
	else if (gameState == STOPPED_DEAD)
	{
		if (input == "enter")
			init();
	}
}

int Game::randomize(int maxNum)				//Returns random number from 1 to maxNum
{
	return rand() % (maxNum - 1) + 1;
}

void Game::update(std::string input, double dTime)				//Maintains input handling, game state management, player movement, etc.
{
	if (gameState == RUNNING)
	{
		std::cout << food.pos.x << ", " << food.pos.y << std::endl;
		checkCollisions();
		handleInput(input);

		tCounter += dTime / 2;

		if (tCounter >= playerSpeed)
		{
			tCounter = 0.0f;
			player.move();
		}
	}
	else
	{
		handleInput(input);
	}
}

std::vector<Dot> Game::dotsToRender()				//Returns vector of tiles for Engine to be rendered
{
	std::vector<Dot> result;
	result.push_back(food);
	for (unsigned int i = 0; i < player.body.size(); ++i)
	{
		result.push_back(player.body.at(i));
	}
	return result;
}
