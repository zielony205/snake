#pragma once
#include "Vec2.h"

typedef enum {PLAYER, FOOD} type;

class Dot
{
public:
	Vec2 pos;
	type dType;

	Dot();
	Dot(Vec2 position, type dotType);
};
