#include "Engine.h"



int main()
{
	Engine eng;
	if (eng.init())
		return 1;

	while (!eng.quit)
	{
		eng.getInput();
		eng.clearScreen();
		eng.drawTile(Vec2());
	}
	return 0;
}
