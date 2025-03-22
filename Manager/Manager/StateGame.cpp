#include "StateGame.hpp"
#include "Cannon.h"
#include "Player.h"
#include "Ultime.h"
#include "Tir.h"

namespace
{
	Cannon gunBig;
	Cannon gunSmol1;
	Cannon gunSmol2;
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
}

void StateGame::DeInit()
{
	gunBig.~Cannon();
	gunSmol1.~Cannon();
	gunSmol2.~Cannon();
}

//sf::Vector2f smallGun1MuzzleL = { -11, -39 };
//sf::Vector2f smallGun1MuzzleR = { 14, -39 };
//sf::Vector2f smallGun2MuzzleL = { 10, -39 };
//sf::Vector2f smallGun2MuzzleR = { -14, -39 };
//sf::Vector2f bigGunMuzzle = { 16,137 };