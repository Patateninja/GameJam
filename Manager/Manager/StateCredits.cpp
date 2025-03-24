#include "StateCredits.h"
#include "StateMachine.hpp"

namespace StateCredits
{
	sf::Sprite creditsFond;
	sf::Texture creditsFondTexture;
	sf::Vector2f creditsFondPos;
}

void StateCredits::Init()
{
	Sound::StopAllMusic();
	Sound::PlayMusic("MusicCrédits");
	creditsFondTexture.loadFromFile("../Ressources/Textures/credits.png");
	creditsFond.setScale(sf::Vector2f(0.5f, 0.5f));
	creditsFond.setTexture(creditsFondTexture);
	creditsFond.setPosition(creditsFondPos);
}

void StateCredits::Update()
{
	// si touche enter appuyée, retour au menu
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		StateMachine::ChangeState(MENU);
	}
}

void StateCredits::Display(sf::RenderWindow& _window)
{
	_window.draw(creditsFond);
}

void StateCredits::DeInit()
{

}
