#include "StateGame.hpp"

namespace
{
	sf::RectangleShape rect;
}

void StateGame::Init()
{
	rect.setSize(sf::Vector2f(10, 10));
	rect.setPosition(sf::Vector2f(400, 300));
}

void StateGame::Update()
{
}

void StateGame::Display(sf::RenderWindow& _window)
{
	_window.draw(rect);
}

void StateGame::DeInit()
{
	//DeInit
}