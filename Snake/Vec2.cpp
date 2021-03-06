#include "Vec2.h"

Vec2::Vec2()
{
}

Vec2::~Vec2()
{
}

Vec2::Vec2(int x, int y)
{
	this->x = x;
	this->y = y;
}


void Vec2::setPos(Vec2 pos)
{
	this->x = pos.x;
	this->y = pos.y;
}

void Vec2::setPos(int x, int y)
{
	this->x = x;
	this->y = y;
}


void Vec2::translate(Vec2 vec)
{
	this->x += vec.x;
	this->y += vec.y;
}

void Vec2::translate(int x, int y)
{
	this->x += x;
	this->y += y;
}

Vec2 Vec2::operator+(Vec2 vec)
{
	vec.x += this->x;
	vec.y += this->y;

	return vec;
}

bool Vec2::operator==(Vec2 vec)
{
	if (this->x == vec.x && this->y == vec.y)
		return true;
	else
		return false;
}