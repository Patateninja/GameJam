#include "StateGame.hpp"
#include "Ennemy.hpp"

namespace
{
	sf::RectangleShape rect;

	std::vector<Obstacle*> obsList;

	std::list<Enemy*> _EnemyList;
}

void StateGame::Init()
{
	rect.setSize(sf::Vector2f(10, 10));
	rect.setPosition(sf::Vector2f(400, 300));

	CreateObstacle(sf::Vector2f(1600.f, 800.f), CACTUS, obsList);
	CreateObstacle(sf::Vector2f(1400.f, 200.f), ROCK, obsList);
	CreateObstacle(sf::Vector2f(300.f, 600.f), BIG_ROCK, obsList);

	Spawn(sf::Vector2f(10.f, 10.), NORMAL, _EnemyList);
	Spawn(sf::Vector2f(500.f, 10.), NORMAL, _EnemyList);
	Spawn(sf::Vector2f(10.f, 500.), NORMAL, _EnemyList);

}

void StateGame::Update()
{
	for (std::list<Enemy*>::iterator it = _EnemyList.begin(); it != _EnemyList.end();)
	{
		Enemy* enemy = *it;
		if (enemy->update(obsList, _EnemyList))
		{
			++it;
		}
		else
		{
			break;
		}
	}
	
}

void StateGame::Display(sf::RenderWindow& _window)
{
	_window.draw(rect);

	for (Enemy* enemy : _EnemyList)
	{
		enemy->display(_window);
	}
	

	for (Obstacle* obs : obsList)
	{
		obs->Draw(_window);
	}
}

void StateGame::DeInit()
{
	_EnemyList.clear();
	obsList.clear();
}