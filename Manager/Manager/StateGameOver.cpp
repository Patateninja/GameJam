#include "StateGameOver.h"
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
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
