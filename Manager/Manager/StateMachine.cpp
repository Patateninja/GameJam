#include "StateMachine.hpp"




namespace
{
	State m_CurrentState = MENU;
	bool isPaused = false;
}

State StateMachine::GetState()
{
	return m_CurrentState;
}

void StateMachine::ChangeState(State _state)
{
	if (_state != m_CurrentState)
	{
		switch (m_CurrentState)
		{
		case MENU:
			StateMenu::DeInit();
			break;
		case TUTO:
			StateTuto::DeInit();
			break;
		case SETTINGS:
			StateGame::DeInit();
			break;
		case GAME:
			StateGame::DeInit();
			break;
		case CREDITS:
			StateCredits::DeInit();
			break;
		case GAMEOVER:
			StateGameOver::DeInit();
			break;
		}

		m_CurrentState = _state;

		StateInit();
	}
}

void StateMachine::StateInit()
{
	StateSettings::Init();
	switch (m_CurrentState)
	{
		case MENU:
			StateMenu::Init();
			break;
		case GAME:
			StateGame::Init();
			break;
		case SETTINGS:
			StateSettings::Init();
			break;
	}
}

void StateMachine::StateEvent()
{

}

void StateMachine::StateUpdate()
{
	switch (m_CurrentState)
	{
		case MENU:
			if (!isPaused)
			{
				StateMenu::Update();
			}
			else
			{
				StateSettings::Update();
			}
			break;
		case GAME:
			if (!isPaused)
			{
				StateGame::Update();
			}
			else
			{
				StateSettings::Update();
			}
			break;
		case QUIT:
			break;
	}
}

void StateMachine::StateDisplay(sf::RenderWindow& _window)
{
	_window.clear();

	switch (m_CurrentState)
	{
		case MENU:
			if (!isPaused)
			{
				StateMenu::Display(_window);
			}
			else
			{
				StateSettings::Display(_window);
			}
			break;
		case GAME:
			if (!isPaused)
			{
				StateGame::Display(_window);
			}
			else
			{
				StateSettings::Display(_window);
			}
			break;
		case QUIT:
			_window.close();
			break;
	}

	_window.display();
}

void StateMachine::toggleIsPaused()
{
	if (isPaused)
	{
		isPaused = false;
	}
	else
	{
		isPaused = true;
	}
}