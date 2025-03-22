#include "StateSettings.hpp"

namespace StateSettings
{
	sf::Sprite settingsMenuBackground;
	sf::Texture settingsTexture;
}

void StateSettings::Init()
{
	settingsTexture.loadFromFile("../Ressources/Textures/settings.png");
	settingsMenuBackground.setTexture(settingsTexture);
}

void StateSettings::Update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		StateMachine::toggleIsPaused();
	}
}

void StateSettings::Display(sf::RenderWindow& _window)
{
	_window.draw(settingsMenuBackground);
}

void StateSettings::DeInit()
{

}