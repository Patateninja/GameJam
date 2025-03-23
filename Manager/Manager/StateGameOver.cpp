#include "StateGameOver.h"
#include "StateMachine.hpp"

namespace StateGameOver
{
	sf::Sprite gameOverFond;
	sf::Texture gameOverFondTexture;
	sf::Vector2f gameOverFondPos;
}

void StateGameOver::Init()
{
	gameOverFondTexture.loadFromFile("../Ressources/Textures/game_over.png");
	gameOverFond.setTexture(gameOverFondTexture);
	gameOverFond.setPosition(gameOverFondPos);
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
