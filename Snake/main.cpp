#include "Engine.h"



int main()
{
	Engine eng;
	if (eng.init())
		return 1;

	while (!eng.quit)
	{
		eng.mainLoop();
	}
	return 0;
}
