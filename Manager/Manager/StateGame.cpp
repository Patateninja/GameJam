#include "StateGame.hpp"
#include "Ennemy.hpp"
#include "IA.hpp"

namespace
{
	sf::RectangleShape rect;
	Enemy enemy(sf::Vector2f(300.f, 400.f), NORMAL);
}

void StateGame::Init()
{
	rect.setSize(sf::Vector2f(10, 10));
	rect.setPosition(sf::Vector2f(400, 300));
}

void StateGame::Update()
{
	enemy.update();
}

void StateGame::Display(sf::RenderWindow& _window)
{
	_window.draw(rect);
	enemy.display(_window);
}

void StateGame::DeInit()
{
	//DeInit
}