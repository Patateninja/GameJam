#include "Tools.h"

float getdeltaTime()
{
	static sf::Clock clock;
	static float deltaTime = 0;
	deltaTime = clock.restart().asSeconds();
	if (deltaTime > 0.1f)
	{
		deltaTime = 0.1f;
	}
	return deltaTime;
}