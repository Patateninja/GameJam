#include "StateMachine.hpp"


namespace
{
	State m_CurrentState = INTRO;
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
		case INTRO:
			StateIntro::DeInit();
			break;
		case MENU:
			StateMenu::DeInit();
			break;
		case SETTINGS:
			StateGame::DeInit();
			break;
		case GAME:
			StateGame::DeInit();
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
	case INTRO:
		StateIntro::Init();
		break;
	case MENU:
		StateMenu::Init();
		break;
	case TUTO:
		StateTuto::Init();
		break;
	case GAME:
		StateGame::Init();
		break;
	case CREDITS:
		StateCredits::Init();
		break;
	case SETTINGS:
		StateSettings::Init();
		break;
	case GAMEOVER:
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
	case INTRO:
		StateIntro::Update();
		break;
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
	case TUTO:
		StateTuto::Update();
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
	case CREDITS:
		StateCredits::Update();
		break;
	case QUIT:
		break;
	case GAMEOVER:
		StateGameOver::Update();
		break;
	}
}

void StateMachine::StateDisplay(sf::RenderWindow& _window)
{
	//_window.clear();

	switch (m_CurrentState)
	{
	case INTRO:
		StateIntro::Display(_window);
		break;
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
	case TUTO:
		StateTuto::Display(_window);
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
	case CREDITS:
		StateCredits::Display(_window);
		break;
	case QUIT:
		_window.close();
		break;
	case GAMEOVER:
		StateGameOver::Display(_window);
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