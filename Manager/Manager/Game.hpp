#pragma once
#include "SFML/Graphics.hpp"

namespace Game
{
	void Init();
	void Update();
	void Display(sf::RenderWindow& _window);
	void DeInit();
};