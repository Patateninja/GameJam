#include "Surchauffe.h"
#include <iostream>

namespace Surchauffe
{
	float timerSurchauffe = 0;
	float timerSurchauffeMaxValue = 5;
	float timerSurchauffeDecrease = 1;

	bool surchauffe = false;

	sf::Sprite surchauffeSprite;
	sf::Texture surchauffeTexture;

	sf::IntRect surchauffeRect = {0,0,50,500};
}

#pragma region Getter and Setter

float Surchauffe::getTimerSurchauffe()
{
	return timerSurchauffe;
}

void Surchauffe::setTimerSurchauffe(float _timerSurchauffe)
{
	timerSurchauffe = _timerSurchauffe;
}

bool Surchauffe::getSurchauffe()
{
	return surchauffe;
}

void Surchauffe::setSurchauffe(bool _surchauffe)
{
	surchauffe = _surchauffe;
}

float Surchauffe::getTimerSurchauffeMaxValue()
{
	return timerSurchauffeMaxValue;
}

void Surchauffe::setTimerSurchauffeMaxValue(float _timerSurchauffeMaxValue)
{
	timerSurchauffeMaxValue = _timerSurchauffeMaxValue;
}

float Surchauffe::getTimerSurchauffeDecrease()
{
	return timerSurchauffeDecrease;
}

void Surchauffe::setTimerSurchauffeDecrease(float _timerSurchauffeDecrease)
{
	timerSurchauffeDecrease = _timerSurchauffeDecrease;
}


#pragma endregion

void Surchauffe::IncrementationTimer(float _timer)
{
	timerSurchauffe += _timer * getDeltaTime();
}

void Surchauffe::DecrementationTimer(float _timer)
{
	timerSurchauffe -= timerSurchauffeDecrease * getDeltaTime();
	if (timerSurchauffe < 0)
	{
		timerSurchauffe = 0;
	}
}

void Surchauffe::Init()
{
	surchauffeTexture.loadFromFile("../Ressources/Textures/surchauffe_bar.png");
	surchauffeSprite.setTexture(surchauffeTexture);
	surchauffeSprite.setTextureRect(surchauffeRect);
}

void Surchauffe::Update()
{
	// TODO Temporaire pour tester
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !surchauffe) IncrementationTimer(1.f);
	//if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !surchauffe) DecrementationTimer(1.f);

	surchauffeRect.height = timerSurchauffe * 100;
	surchauffeSprite.setTextureRect(surchauffeRect);

	if (timerSurchauffe > timerSurchauffeMaxValue)
	{
		surchauffe = true;
	}

	if (surchauffe)
	{
		DecrementationTimer(timerSurchauffeDecrease);
		
		if (timerSurchauffe <= 0)
		{
			timerSurchauffe = 0;
			surchauffe = false;
		}
	}
}

void Surchauffe::Display(sf::RenderWindow& _window)
{
	_window.draw(surchauffeSprite);
}

void Surchauffe::Destroy()
{

}
