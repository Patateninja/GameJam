#pragma once
#include "SFML/Graphics.hpp"

#include "Button.hpp"

namespace StateMenu
{
	void Init();
	void Update();
	void Display(sf::RenderWindow& _window);
	void DeInit();
};