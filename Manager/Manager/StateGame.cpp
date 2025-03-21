#include "StateGame.hpp"
#include "Ennemy.hpp"

namespace
{
	sf::RectangleShape rect;

	sf::RenderWindow window(sf::VideoMode(1920, 1080), "A* Pathfinding", sf::Style::Fullscreen);
	sf::RectangleShape rectangle(sf::Vector2f(64.f, 64.f));
	sf::CircleShape circle(32.f);
	sf::Clock clock;

	Graph tilemap(10, 10, false);
	IA starFinder('e', nullptr, nullptr);
	Ennemy player(starFinder.getPath());
	bool editing = true;
}

void StateGame::Init()
{
	rect.setSize(sf::Vector2f(10, 10));
	rect.setPosition(sf::Vector2f(400, 300));
}

void StateGame::Update()
{
	starFinder.Astar(&tilemap);
	player.setPlayerPath(starFinder.getPath());
	player.followPath();
	clock.restart();
}

void StateGame::Display(sf::RenderWindow& _window)
{
	_window.draw(rect);
}

void StateGame::DeInit()
{
	//DeInit
}