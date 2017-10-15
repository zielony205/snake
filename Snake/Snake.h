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
	~Snake();

	void move();
	bool changeDirection(Vec2 newDirection);
	void grow();
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

	growNextFrame = false;
}

Vec2 Snake::findBlockedDirection()
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
	return result;
}

void Snake::update()
{
	headPosition = body.at(0).pos;
	neckPosition = body.at(1).pos;

	findBlockedDirection();
}

void Snake::move()
{
	if (!growNextFrame)
		body.pop_back();
	else
		growNextFrame = false;

	body.insert(body.begin(), Dot(Vec2(headPosition + headDirection), PLAYER));

	update();
}

bool Snake::changeDirection(Vec2 newDirection)
{
	if (newDirection == findBlockedDirection())
		return false;
	else
	{
		headDirection = newDirection;
		return true;
	}
}

void Snake::grow()
{
	growNextFrame = true;
}

