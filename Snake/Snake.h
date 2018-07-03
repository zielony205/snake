#pragma once

#include "Vec2.h"
#include "Dot.h"
#include <vector>

class Snake
{
private:
	bool growNextFrame;

	Vec2 findBlockedDirection();
	void update();

public:
	Vec2 headPosition;
	Vec2 headDirection;
	Vec2 neckPosition;
	Vec2 blockedDirection;
	std::vector<Dot> body;

	Snake();
	Snake(Vec2 position, Vec2 direction, int numberOfSegments);

	void move();
	bool changeDirection(Vec2 newDirection);
	void grow();
};

