#pragma once
#include "Vec2.h"

class Engine
{
public:


	Engine();
	~Engine();

	Vec2 getInput();
	void renderFrame();

};

