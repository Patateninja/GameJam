#include "StateGame.hpp"
#include "Cannon.h"
#include "Player.h"
#include "Ultime.h"
#include "Tir.h"
#include "Ennemy.hpp"
#include "UI.h"

namespace
{
	Cannon gunBig;
	Cannon gunSmol1;
	Cannon gunSmol2;

	sf::RectangleShape rect;

	std::list<Enemy*> _EnemyList;
}

void StateGame::Init()
{
	Player::Init();
	initCannon();
	initTir();
	Ultime::InitUltime();
	UI::Init();
	gunBig = Cannon(BIGCANNON);
	gunSmol1 = Cannon(SMOLCANNON1);
	gunSmol2 = Cannon(SMOLCANNON2);

	Ultime::InitUltime();
	rect.setSize(sf::Vector2f(10, 10));
	rect.setPosition(sf::Vector2f(400, 300));

	/*Spawn(sf::Vector2f(700.f, 100.f), KAMIKAZE, _EnemyList);
	Spawn(sf::Vector2f(700.f, 200.f), KAMIKAZE, _EnemyList);
	Spawn(sf::Vector2f(700.f, 300.f), KAMIKAZE, _EnemyList);
	Spawn(sf::Vector2f(700.f, 400.f), KAMIKAZE, _EnemyList);
	Spawn(sf::Vector2f(700.f, 500.f), KAMIKAZE, _EnemyList);
	Spawn(sf::Vector2f(700.f, 600.f), KAMIKAZE, _EnemyList);
	Spawn(sf::Vector2f(700.f, 700.f), KAMIKAZE, _EnemyList);
	Spawn(sf::Vector2f(700.f, 800.f), KAMIKAZE, _EnemyList);
	Spawn(sf::Vector2f(700.f, 900.f), KAMIKAZE, _EnemyList);
	Spawn(sf::Vector2f(700.f, 1000.f), KAMIKAZE, _EnemyList);
	Spawn(sf::Vector2f(700.f, 1100.f), KAMIKAZE, _EnemyList);
	Spawn(sf::Vector2f(700.f, 1200.f), KAMIKAZE, _EnemyList);
	Spawn(sf::Vector2f(700.f, 1300.f), KAMIKAZE, _EnemyList);
	Spawn(sf::Vector2f(700.f, 1400.f), KAMIKAZE, _EnemyList);
	Spawn(sf::Vector2f(700.f, 1500.f), SPEEDSTER, _EnemyList);*/
}

void StateGame::Update()
{
	if (_EnemyList.size() < 50)
	{
		int x = (rand() % 4000) - 1920;
		int y = 0;
		if (x < 0 || x > 1920)
		{
			y = (rand() % 3100) - 1080;
		}
		else
		{
			y = (rand() % 2 == 1 ? 0 : 1080);
		}


		Spawn(sf::Vector2f(x, y), static_cast<EnemyClass>(rand() % 4), _EnemyList);
	}


	Player::Update(_EnemyList);
	Ultime::UpdateUltime();
	UI::Update(Player::GetHP());

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

	std::list<Tir> tirs = getTirList();
	for (auto& tir : tirs)
	{
		tir.Update();
		if (!tir.isAlive()) tir.~Tir();
	}
	//for (std::list<Tir>::iterator it = tirs.begin(); it != tirs.end();)
	//{
	//	if (!it->isAlive())
	//	{
	//		it = tirs.erase(it);
	//	}
	//	else
	//	{
	//		++it;
	//	}
	//}

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
	Ultime::DisplayUltime(_window);
	UI::Display(_window);
}

void StateGame::DeInit()
{
	gunBig.~Cannon();
	gunSmol1.~Cannon();
	gunSmol2.~Cannon();
	_EnemyList.clear();
}
