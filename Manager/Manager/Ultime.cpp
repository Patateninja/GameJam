#include "Ultime.h"
#include <iostream>

namespace Ultime
{
	sf::Sprite ultimeSprite;
	sf::Texture ultimeTexture;
	float ultimeAngle = 90.f;
	float ultimeRotationSpeed = 100.f;

	float delayPlayerToStartCooldown = 1.f;

	bool isActif = false;

	bool cooldownPlayer1 = false;
	bool cooldownPlayer2 = false;

	bool startUltime = false;
}

void Ultime::SetStateUltime(bool _state) { startUltime = _state; }

void Ultime::InitUltime()
{
	ultimeTexture.loadFromFile("../Ressources/Textures/FDP.png");
	ultimeSprite.setTexture(ultimeTexture);
	ultimeSprite.setOrigin(ultimeSprite.getGlobalBounds().width / 2, ultimeSprite.getGlobalBounds().height / 2);
	
}

void Ultime::UpdateUltime()
{
	static float timerInputP1 = 0;
	static float timerInputP2 = 0;
	static float timerInputPlayer1 = 0;
	static float timerInputPlayer2 = 0;

	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) startUltime = true;
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::T)) isActif = false;


	if (startUltime)
	{


		if (cooldownPlayer1) timerInputPlayer1 += getDeltaTime();

		if (timerInputPlayer1 > 5.f)
		{
			timerInputPlayer1 = 0;
			cooldownPlayer1 = false;
		}

		if (cooldownPlayer2) timerInputPlayer2 += getDeltaTime();

		if (timerInputPlayer2 > 5.f)
		{
			timerInputPlayer2 = 0;
			cooldownPlayer2 = false;
		}



		//////////////////////////////////////////////// PLAYER 1 ////////////////////////////////////////////////

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && !cooldownPlayer1)
		{
			timerInputP1 += getDeltaTime();

			if (timerInputP1 > delayPlayerToStartCooldown && !isActif)
			{
				cooldownPlayer1 = true;
			}
		}
		else
		{
			timerInputP1 = 0;
		}

		//////////////////////////////////////////////// PLAYER 2 ////////////////////////////////////////////////

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::RControl) && !cooldownPlayer2)
		{
			timerInputP2 += getDeltaTime();

			if (timerInputP2 > delayPlayerToStartCooldown && !isActif)
			{
				cooldownPlayer2 = true;
			}
		}
		else
		{
			timerInputP2 = 0;
		}

		if (!cooldownPlayer1 && !cooldownPlayer2 && sf::Keyboard::isKeyPressed(sf::Keyboard::RControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) isActif = true;

		// Rotate
		if (ultimeAngle < 270.f && isActif)
		{
			ultimeAngle += ultimeRotationSpeed * getDeltaTime();
			ultimeSprite.setRotation(ultimeAngle);
		}
		else
		{
			ultimeAngle = 90.f;
			isActif = false;
		}

	}

}

void Ultime::DisplayUltime(sf::RenderWindow& _window)
{

	if (startUltime && isActif)
	{
		ultimeSprite.setPosition(_window.getSize().x / 2, _window.getSize().y / 2);
		_window.draw(ultimeSprite);
	}

}
