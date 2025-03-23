#include "Ultime.h"
#include "Math.h"
#include <iostream>

namespace Ultime
{
	sf::Sprite ultimeSprite;
	sf::Sprite ultimeSpriteBase;
	sf::Texture ultimeTexture;
	sf::Vector2f tmpPlayerPos = { 1000.f, 500.f };
	sf::IntRect ultimeRect = { 0, 0, 141, 93 };

	float ultimeAngle = 90.f;
	float ultimeRotationSpeed = 100.f;
	float delayPlayerToStartCooldown = 1.f;
	float ultimeScaleX;
	float lerpUltime = 0.f;
	float timerSondUltime = 0.f;

	bool isActif = false;

	bool cooldownPlayer1 = false;
	bool cooldownPlayer2 = false;

	bool startUltime = false;

	int ultimeFrame = 0;
}

void Ultime::SetStateUltime(bool _state) { startUltime = _state; }

void Ultime::InitUltime()
{
	ultimeTexture.loadFromFile("../Ressources/Textures/lazer_L_564_H_93.png");
	ultimeSprite.setTexture(ultimeTexture);
	ultimeSprite.setTextureRect(ultimeRect);
	ultimeSprite.setOrigin(-2.f, ultimeSprite.getGlobalBounds().height / 2 + 3.f);
	ultimeSpriteBase.setTexture(ultimeTexture);
	ultimeSpriteBase.setOrigin(-2.f, ultimeSpriteBase.getGlobalBounds().height / 2 + 3.f);
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
}

void Ultime::DisplayUltime(sf::RenderWindow& _window)
{
	if (startUltime && isActif)
	{
		if (ultimeScaleX < 10)
			ultimeScaleX += getDeltaTime() * 15;

		ultimeFrame = 4;
		ultimeRect.left = ultimeFrame * ultimeRect.width;
		ultimeSprite.setTextureRect(ultimeRect);

		lerpUltime = Math::lerp2D(lerpUltime, 1.5f, 0.65f * getDeltaTime());

		ultimeSprite.setScale(ultimeScaleX, lerpUltime);

	}

	if (ultimeAngle < 270.f && isActif)
	{
		timerSondUltime += getDeltaTime();

		if (timerSondUltime > 0.2f)
		{
			Sound::PlaySound("ultimeLaser");
			timerSondUltime = 0.f;
		}

		ultimeAngle += ultimeRotationSpeed * getDeltaTime();
		ultimeSprite.setRotation(ultimeAngle);
		ultimeSpriteBase.setRotation(ultimeAngle);

		if (startUltime && isActif)
		{
			ultimeSprite.setPosition(tmpPlayerPos);
			_window.draw(ultimeSprite);
			ultimeSpriteBase.setPosition(tmpPlayerPos);
			_window.draw(ultimeSpriteBase);
		}

		ultimeSprite.setRotation(ultimeAngle + 180.f);
		ultimeSpriteBase.setRotation(ultimeAngle + 180.f);
		
		if (startUltime && isActif)
		{
			ultimeSprite.setPosition(tmpPlayerPos);
			_window.draw(ultimeSprite);

			if (lerpUltime < 0.25f)
			{
				ultimeFrame = 0;
				ultimeRect.left = ultimeFrame * ultimeRect.width;
				ultimeSpriteBase.setTextureRect(ultimeRect);
			}
			else if (lerpUltime < 0.65f)
			{
				ultimeFrame = 1;
				ultimeRect.left = ultimeFrame * ultimeRect.width;
				ultimeSpriteBase.setTextureRect(ultimeRect);
			}
			else
			{
				ultimeFrame = 2;
				ultimeRect.left = ultimeFrame * ultimeRect.width;
				ultimeSpriteBase.setTextureRect(ultimeRect);
			}

			ultimeSpriteBase.setPosition(tmpPlayerPos);
			_window.draw(ultimeSpriteBase);
		}
	}
	else
	{
		ultimeAngle = 90.f;
		isActif = false;
		ultimeFrame = 0;
		lerpUltime = 0.0f;
		ultimeScaleX = 0.0f;
	}
}
