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

