#include "StateMenu.hpp"

#include "StateMachine.hpp"

namespace
{
	sf::RectangleShape rect;
}

void StateMenu::Init()
{
	rect.setSize(sf::Vector2f(10, 10));
	rect.setPosition(sf::Vector2f(400, 300));

	StateMachine::MainMenu = ActualMenu();
}

void StateMenu::Update()
{
	if (StateMachine::MainMenu.GetList().size() == 0)
	{
		StateMachine::MainMenu.Add(new Button(TO_MENU, sf::Vector2f(150.f, 75.f), StateMachine::MainMenu));
		StateMachine::MainMenu.Add(new Button(TO_GAME, sf::Vector2f(150.f, 75.f), StateMachine::MainMenu));
		StateMachine::MainMenu.Add(new Button(TO_QUIT, sf::Vector2f(150.f, 75.f), StateMachine::MainMenu));
	}

	switch (StateMachine::MainMenu.Update())
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

void StateMenu::Display(Window& _window)
{
	_window.Draw(rect);
}

void StateMenu::DeInit()
{
	//DeInit
}