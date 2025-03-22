#pragma once

#include "tools.h"
#include "stateMachine.hpp"

namespace StateSettings
{
	void Init();
	void Update();
	void Display(sf::RenderWindow& _window);
	void DeInit();
}