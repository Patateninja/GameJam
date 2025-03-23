#pragma once
#include "StateMenu.hpp"
#include "StateGame.hpp"
#include "StateSettings.hpp"
#include "StateCredits.h"
#include "StateTuto.h"
#include "StateGameOver.h"
#include "StateIntro.h"

typedef enum State
{
	INTRO,
	MENU,
	SETTINGS,
	GAME,
	QUIT,
} State;

namespace StateMachine
{
	State GetState(); // Get the current state

	void ChangeState(State _state); //Set the current state

	void StateInit();
	void StateEvent();
	void StateUpdate();
	void StateDisplay(sf::RenderWindow& _window);

	void toggleIsPaused();
};