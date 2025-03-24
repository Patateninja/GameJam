#include "StateGame.hpp"
#include "Cannon.hpp"
#include "Player.hpp"
#include "Ultime.hpp"
#include "Tir.hpp"
#include "Enemy.hpp"
#include "UI.hpp"

namespace
{
	Cannon gunBig;
	Cannon gunSmol1;
	Cannon gunSmol2;
	sf::Sprite back;
	sf::Texture backTex;

	sf::RectangleShape rect;

	std::vector<Obstacle*> obsList;

	std::list<Enemy*> _EnemyList;

	sf::Sprite decor;
	sf::Texture decroTexture;
}

void StateGame::Init()
{
	Sound::StopAllMusic();
	Sound::PlayMusic("MusicGame");
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

	backTex.loadFromFile("../Ressources/Textures/FOND 3.png");
	backTex.setRepeated(true);
	back.setTexture(backTex);

	decroTexture.loadFromFile("../Ressources/Textures/d.png");
	decor.setTexture(decroTexture);

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

	for (auto& tir : getTirList())
	{
		tir.Update();
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
	_window.draw(back);
	for (Obstacle* obs : obsList)
	{
		obs->Draw(_window);
	}

	decor.setPosition(sf::Vector2f(528, 315));
	decor.setTextureRect(sf::IntRect(6 * 88, 0, 88, 57));
	_window.draw(decor);

	decor.setPosition(sf::Vector2f(142, 852));
	decor.setTextureRect(sf::IntRect(2 * 88, 0, 88, 57));
	_window.draw(decor);

	decor.setPosition(sf::Vector2f(988, 1000));
	decor.setTextureRect(sf::IntRect(11 * 88, 0, 88, 57));
	_window.draw(decor);

	decor.setPosition(sf::Vector2f(025, 625));
	decor.setTextureRect(sf::IntRect(3 * 88, 0, 88, 57));
	_window.draw(decor);

	for (Enemy* enemy : _EnemyList)
	{
		enemy->Display(_window);
	}

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

	Ultime::DisplayUltime(_window);
	UI::Display(_window);
}

void StateGame::DeInit()
{
	gunBig.~Cannon();
	gunSmol1.~Cannon();
	gunSmol2.~Cannon();
	_EnemyList.clear();
	obsList.clear();
}
