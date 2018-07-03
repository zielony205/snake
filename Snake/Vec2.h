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

