#pragma once
#include "Vec2.h"
#include "Dot.h"

class Engine
{
public:


	Engine();
	~Engine();

	Vec2 getInput();
	void renderFrame();
	bool collisionCheck(Dot objA, Dot objB);

};

