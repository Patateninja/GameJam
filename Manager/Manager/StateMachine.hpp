#pragma once
#include "StateMenu.hpp"
#include "StateGame.hpp"
#include "Window.h"

typedef enum State
{
	MENU,
	GAME,
	QUIT,
} State;

namespace StateMachine
{
	ActualMenu MainMenu = ActualMenu();

	State GetState(); // Get the current state

	void ChangeState(State _state); //Set the current state

	void StateInit();
	void StateEvent();
	void StateUpdate();
	void StateDisplay(Window& _window);
};