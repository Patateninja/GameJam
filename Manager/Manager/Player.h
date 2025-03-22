#pragma once

#include "Tools.h"


namespace Player
{
	float GetPlayerSpeed();
	void SetPlayerSpeed(float value);

	float GetRotateSpeed();
	void SetRotateSpeed(float value);
	void setTeslaState(const bool state);

	sf::Vector2f GetPlayerPosition();
	float GetPlayerRotation();

	void Init();

	void Update();

	void Display(sf::RenderWindow& _window);

}