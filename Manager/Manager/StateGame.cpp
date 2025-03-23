#include "StateGame.hpp"
#include "Cannon.h"
#include "Player.h"
#include "Ultime.h"
#include "Tir.h"
#include "Ennemy.hpp"

namespace
{
	Cannon gunBig;
	Cannon gunSmol1;
	Cannon gunSmol2;

	sf::RectangleShape rect;

	std::vector<Obstacle*> obsList;

	std::list<Enemy*> _EnemyList;
}

void StateGame::Init()
{
	Player::Init();
	initCannon();
	initTir();
	gunBig = Cannon(BIGCANNON);
	gunSmol1 = Cannon(SMOLCANNON1);
	gunSmol2 = Cannon(SMOLCANNON2);

	Ultime::InitUltime();
	rect.setSize(sf::Vector2f(10, 10));
	rect.setPosition(sf::Vector2f(400, 300));

	CreateObstacle(sf::Vector2f(1600.f, 800.f), CACTUS, obsList);
	CreateObstacle(sf::Vector2f(1400.f, 200.f), ROCK, obsList);
	CreateObstacle(sf::Vector2f(300.f, 600.f), BIG_ROCK, obsList);

	Spawn(sf::Vector2f(10.f, 10.), NORMAL, _EnemyList);
	Spawn(sf::Vector2f(500.f, 10.), TANK, _EnemyList);
	Spawn(sf::Vector2f(10.f, 500.), SPEEDSTER, _EnemyList);
	Spawn(sf::Vector2f(10.f, 10.), TANK, _EnemyList);
	Spawn(sf::Vector2f(500.f, 10.), TANK, _EnemyList);
	Spawn(sf::Vector2f(10.f, 500.), TANK, _EnemyList);
	Spawn(sf::Vector2f(10.f, 300.f), KAMIKAZE, _EnemyList);
	Spawn(sf::Vector2f(300.f, 10.f), KAMIKAZE, _EnemyList);
}

void StateGame::Update()
{
	Player::Update();
	Ultime::UpdateUltime();

	gunBig.Update();
	gunBig.Rotate(
		sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Left) -
		sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Right)
	); 

	gunSmol1.Update();
	gunSmol1.Rotate(
		sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A) -
		sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D)
	);
	gunSmol2.Update();
	gunSmol2.Rotate(
		sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A) -
		sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D)
	);

	for (auto& tir : getTirList())
	{
		tir.Update();
		tir.destroyIfDead();
	}

	for (std::list<Enemy*>::iterator it = _EnemyList.begin(); it != _EnemyList.end();)
	{
		Enemy* enemy = *it;
		if (enemy->Update(obsList, _EnemyList))
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
	Player::Display(_window);
	gunBig.Display(_window);
	gunSmol1.Display(_window);
	gunSmol2.Display(_window);
	Ultime::DisplayUltime(_window);
	for (auto& tir : getTirList())
	{
		tir.Display(_window);
	}
	_window.draw(rect);

	for (Enemy* enemy : _EnemyList)
	{
		enemy->Display(_window);
	}
	

	for (Obstacle* obs : obsList)
	{
		obs->Draw(_window);
	}
}

void StateGame::DeInit()
{
	gunBig.~Cannon();
	gunSmol1.~Cannon();
	gunSmol2.~Cannon();
	_EnemyList.clear();
	obsList.clear();
}
