#include "StateGameOver.hpp"
#include "StateMachine.hpp"

namespace StateGameOver
{
	sf::Sprite gameOverFond;
	sf::Texture gameOverFondTexture;
}

void StateGameOver::Init()
{
	Sound::StopAllMusic();
	Sound::PlayMusic("MusicCrédits");
	gameOverFondTexture.loadFromFile("../Ressources/Textures/game_over.png");
	gameOverFond.setTexture(gameOverFondTexture);
}

void StateGameOver::Update()
{
	if (Keys::isInteractPressed())
	{
		StateMachine::ChangeState(MENU);
	}
}

void StateGameOver::Display(sf::RenderWindow& _window)
{
	_window.draw(gameOverFond);
}

void StateGameOver::DeInit()
{
}
