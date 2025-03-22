#include "Surchauffe.h"
#include <iostream>

namespace Surchauffe
{
	float timerSurchauffe = 0;
	float timerSurchauffeMaxValue = 5;
	float timerSurchauffeDecrease = 1;

	bool surchauffe = false;
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

// timer = 0;
// ajouter 1 au timer quand on tire
// si timer > 100, on surchauffe
// reduire timer de 1 chaque frame si on tire pas
// si timer < 0, timer = 0
// si on surchauffe, on ne peut plus tirer jusqu'a ce que timer = 0

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

void Surchauffe::init()
{

}

void Surchauffe::update()
{
	// TODO Temporaire pour tester
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !surchauffe) IncrementationTimer(1.f);
	//if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !surchauffe) DecrementationTimer(1.f);

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

void Surchauffe::draw()
{

}

void Surchauffe::destroy()
{

}
