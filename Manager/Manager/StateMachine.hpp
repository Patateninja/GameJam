#pragma once
#include "StateMenu.hpp"
#include "StateGame.hpp"

#include "Button.hpp"

typedef enum State
{
	MENU,
	GAME,
	QUIT,
};

namespace StateMachine
{
	ActualMenu MainMenu;

	State GetState(); // Get the current state

	void ChangeState(State _state); //Set the current state

	void StateInit();
	void StateEvent();
	void StateUpdate();
	void StateDisplay(sf::RenderWindow& _window);
};