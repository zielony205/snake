#pragma once

#include "Vec2.h"
#include "Dot.h"
#include "Snake.h"

class Game
{
private:
	typedef enum { RUNNING, STOPPED_PAUSE, STOPPED_DEAD} gameState;

public:

	int screenWidth;
	int screenHeight;

	int mapWidth;
	int mapHeight;

	int score;

	Snake player;
	Dot food;
	

	Game();

	void spawnFood();
	void spawnSnake();
	void checkCollisions();
	void update();


};