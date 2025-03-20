#pragma once
#include "Menu.hpp"
#include "Game.hpp"

typedef enum State
{
	MENU,
	GAME,
	QUIT,
};

namespace StateMachine
{
		State GetState(); // Get the current state

		void ChangeState(State _state); //Set the current state

		void StateEvent();
		void StateUpdate();
		void StateDisplay(sf::RenderWindow& _window);
};