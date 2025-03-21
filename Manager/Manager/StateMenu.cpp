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
}

void StateMenu::Update()
{
	if (ButtonList::ButtonList.size() == 0)
	{
		ButtonList::Add(new Button(TO_MENU, sf::Vector2f(150.f, 75.f)));
		ButtonList::Add(new Button(TO_GAME, sf::Vector2f(150.f, 75.f)));
		ButtonList::Add(new Button(TO_QUIT, sf::Vector2f(150.f, 75.f)));
	}

	switch (ButtonList::Update())
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
	_window.draw(rect);
}

void StateMenu::DeInit()
{
	//DeInit
}