#include "StateMenu.hpp"

#include "StateMachine.hpp"

namespace
{
	ActualMenu MainMenu = ActualMenu();
}

void StateMenu::Init()
{
	MainMenu = ActualMenu();
}

void StateMenu::Update()
{
	if (MainMenu.GetList().size() == 0)
	{
		MainMenu.Add(new Button(TO_MENU, sf::Vector2f(150.f, 75.f), MainMenu));
		MainMenu.Add(new Button(TO_GAME, sf::Vector2f(150.f, 275.f), MainMenu));
		MainMenu.Add(new Button(TO_QUIT, sf::Vector2f(150.f, 475.f), MainMenu));
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
}

void StateMenu::DeInit()
{
	//DeInit
}