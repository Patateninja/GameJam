#include "StateGame.hpp"
#include "Ennemy.hpp"

namespace
{
	sf::RectangleShape rect;
	Enemy enemy(sf::Vector2f(300.f, 400.f), NORMAL);

	std::vector<Obstacle*> obsList;
	
}

void StateGame::Init()
{
	rect.setSize(sf::Vector2f(10, 10));
	rect.setPosition(sf::Vector2f(400, 300));
}

void StateGame::Update()
{
	if (obsList.size() == 0)
	{
		obsList.push_back(new Obstacle(sf::Vector2f(600.f, 600.f)));
	}

	enemy.update(obsList);
}

void StateGame::Display(sf::RenderWindow& _window)
{
	_window.draw(rect);
	enemy.display(_window);

	for (Obstacle* obs : obsList)
	{
		_window.draw(obs->m_circle);
	}
}

void StateGame::DeInit()
{
	//DeInit
}