#include "StateMenu.hpp"
#include "StateMachine.hpp"
#include <iostream>

namespace
{
	ActualMenu MainMenu = ActualMenu();
}

void StateMenu::Init()
{
	MainMenu = ActualMenu();
}

namespace test
{
	int number = 101;

	void drawCircle(sf::RenderWindow& window, sf::Vector2f pos, float radius, sf::Color color)
	{
		if (number < 0)
			number = 101;
		sf::VertexArray vertex(sf::TriangleFan, number + 1);
		vertex[0].position = pos;
		vertex[0].color = color;
		for (int i = 0; i < number; i++)
		{
			float angle = 2 * 3.14159265359 * i / 100 - 3.14159265359 / 2;
			vertex[i + 1].position = sf::Vector2f(pos.x + cos(angle) * radius, pos.y + sin(angle) * radius);
			vertex[i + 1].color = color;
		}
		window.draw(vertex);
	}

}


void StateMenu::Update()
{
	if (MainMenu.GetList().size() == 0)
	{
		MainMenu.Add(new Button(TO_MENU, sf::Vector2f(150.f, 75.f), MainMenu));
		MainMenu.Add(new Button(TO_GAME, sf::Vector2f(150.f, 275.f), MainMenu));
		MainMenu.Add(new Button(TO_QUIT, sf::Vector2f(150.f, 475.f), MainMenu));
	}
	static float time = 0;

	time += getdeltaTime();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && time > 0.2)
	{
		test::number--;
		time = 0;
	}

	switch (MainMenu.Update())
	{
		case TO_MENU :
			StateMachine::ChangeState(MENU);
			break;
		case TO_GAME :
			StateMachine::ChangeState(GAME);
			break;
		case TO_QUIT :
			StateMachine::ChangeState(QUIT);
			break;
	}



}

void StateMenu::Display(sf::RenderWindow& _window)
{
	MainMenu.Display(_window);
	test::drawCircle(_window, sf::Vector2f(100, 100), 50, sf::Color::Magenta);
}

void StateMenu::DeInit()
{
	//DeInit
}