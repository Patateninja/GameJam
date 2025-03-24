#pragma once
#include "StateMenu.hpp"
#include "StateGame.hpp"
#include "StateSettings.hpp"
#include "StateCredits.hpp"
#include "StateTuto.hpp"
#include "StateGameOver.hpp"
#include "StateIntro.hpp"

typedef enum State
{
	TUTO,
	INTRO,
	MENU,
	SETTINGS,
	GAME,
	GAMEOVER,
	CREDITS,
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