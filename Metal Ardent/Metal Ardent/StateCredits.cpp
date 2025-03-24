#include "StateCredits.hpp"
#include "StateMachine.hpp"
#include "Keys.hpp"

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
	creditsFond.setTexture(creditsFondTexture);
	creditsFond.setPosition(creditsFondPos);
}

void StateCredits::Update()
{
	if (Keys::isInteractPressed)
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
