#pragma once

#include "tools.h"


namespace Player
{
	float GetPlayerSpeed();
	void SetPlayerSpeed(float value);

	float GetRotateSpeed();
	void SetRotateSpeed(float value);

	sf::Sprite GetSpritePlayer();

	void Init();

	void Update();

	void Display(sf::RenderWindow& _window);

}