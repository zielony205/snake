#pragma once

class Vec2
{
public:
	int x;
	int y;

	Vec2();
	Vec2(int x, int y);
	~Vec2();

	void setPos(Vec2 pos);
	void setPos(int x, int y);

	void translate(Vec2 vec);
	void translate(int x, int y);

	Vec2 operator+(Vec2 vec);
	bool operator==(Vec2 vec);
};

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
	Vec2 result;

	result.x += vec.x;
	result.y += vec.y;

	return result;
}

bool Vec2::operator==(Vec2 vec)
{
	if (this->x == vec.x && this->y == vec.y)
		return true;
	else
		return false;
}

