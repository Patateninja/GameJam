#include "StateGame.hpp"
#include "Cannon.h"
#include "Player.h"

namespace
{
	sf::RectangleShape rect;
	Cannon gunBig;
	Cannon gunSmol;
}

void StateGame::Init()
{
	rect.setSize(sf::Vector2f(10, 10));
	rect.setPosition(sf::Vector2f(400, 300));
	initCannon();
	gunBig = Cannon(BIGCANNON);
	gunSmol = Cannon(SMOLCANNON);
	Player::Init();
}

void StateGame::Update()
{
	Player::Update();

	gunBig.Update();
	gunBig.Rotate(
		sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Left) -
		sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Right)
	);


	gunSmol.Update();
	gunSmol.Rotate(
		sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D) -
		sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A)
	);
}

void StateGame::Display(sf::RenderWindow& _window)
{
	gunBig.Display(_window);
	gunSmol.Display(_window);
	Player::Display(_window);
	_window.draw(rect);
}

void StateGame::DeInit()
{
	gunBig.~Cannon();
	gunSmol.~Cannon();
}