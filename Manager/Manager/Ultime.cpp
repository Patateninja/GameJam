#include "Ultime.h"
#include <iostream>

namespace Ultime
{
	sf::Sprite ultimeSprite;
	sf::Texture ultimeTexture;
	sf::Vector2f tmpPlayerPos = { 1000.f, 500.f };
	sf::IntRect ultimeRect = { 0, 0, 342, 94 };

	float ultimeAngle = 90.f;
	float ultimeRotationSpeed = 100.f;
	float delayPlayerToStartCooldown = 1.f;
	float ultimeAnimeTimer = 0.f;

	bool isActif = false;

	bool cooldownPlayer1 = false;
	bool cooldownPlayer2 = false;

	bool startUltime = false;

	int ultimeFrame = 0;
}

void Ultime::SetStateUltime(bool _state) { startUltime = _state; }

void Ultime::InitUltime()
{
	ultimeTexture.loadFromFile("../Ressources/Textures/lazer_L_1710_H_94.png");
	ultimeSprite.setTextureRect(ultimeRect);
	ultimeSprite.setTexture(ultimeTexture);
	ultimeSprite.setOrigin(7.f, ultimeSprite.getGlobalBounds().height / 2 + 6.f);
}

void Ultime::UpdateUltime()
{
	static float timerInputP1 = 0;
	static float timerInputP2 = 0;
	static float timerInputPlayer1 = 0;
	static float timerInputPlayer2 = 0;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) startUltime = true;
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
	}

	if (startUltime && isActif)
	{
		ultimeAnimeTimer += getDeltaTime();

		if (ultimeAnimeTimer > 0.1f && ultimeFrame < 2)
		{
			ultimeRect.left = ultimeFrame * ultimeRect.width;
			ultimeSprite.setTextureRect(ultimeRect);
			ultimeAnimeTimer = 0.0;
			ultimeFrame++;
		}
	}
}

void Ultime::DisplayUltime(sf::RenderWindow& _window)
{
	if (ultimeAngle < 270.f && isActif)
	{
		ultimeAngle += ultimeRotationSpeed * getDeltaTime();
		ultimeSprite.setRotation(ultimeAngle);

		if (startUltime && isActif)
		{
			ultimeSprite.setPosition(tmpPlayerPos);
			_window.draw(ultimeSprite);
		}

		ultimeSprite.setRotation(ultimeAngle + 180.f);

		if (startUltime && isActif)
		{
			ultimeSprite.setPosition(tmpPlayerPos);
			_window.draw(ultimeSprite);
		}
	}
	else
	{
		ultimeAngle = 90.f;
		isActif = false;
		ultimeFrame = 0;
	}
}
