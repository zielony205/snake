#pragma once

#include "Vec2.h"
#include "Dot.h"
#include <vector>

class Snake
{
private:
	void findBlockedDirection();
	void update();

public:
	Vec2 headPosition;
	Vec2 headDirection;
	Vec2 neckPosition;
	Vec2 blockedDirection;

	std::vector<Dot> body;

	Snake(Vec2 position, Vec2 direction, int numberOfSegments);
	~Snake();

	void move(Vec2 direction);
};

Snake::Snake(Vec2 position, Vec2 direction, int numberOfSegments)
{
	headPosition = position;
	headDirection = direction;

	for (int i = 0; i < numberOfSegments; ++i)
	{
		body.push_back(Dot(Vec2(position.x + (direction.x * i), position.y + (direction.y * i)), PLAYER));
	}

	neckPosition = body.at(1).pos;
}

void Snake::findBlockedDirection()
{
	Vec2 result;

	if (headPosition.x == neckPosition.x)
	{
		result.x = 0;
		result.y = neckPosition.y - headPosition.y;
	}
	else
	{
		result.y = 0;
		result.x = neckPosition.x - headPosition.x;
	}

	blockedDirection = result;
}

void Snake::update()
{
	headPosition = body.at(0).pos;
	neckPosition = body.at(1).pos;

	findBlockedDirection();
}

void Snake::move(Vec2 direction)
{
	headDirection = direction;
	body.pop_back();
	body.insert(body.begin(), Dot(Vec2(headPosition + headDirection), PLAYER));

	update();
}
