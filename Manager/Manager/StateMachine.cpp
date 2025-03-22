#include "StateMachine.hpp"

namespace
{
	State m_CurrentState = MENU;
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
	switch (m_CurrentState)
	{
		case MENU:
			StateMenu::Init();
			break;
		case GAME:
			StateGame::Init();
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
		case MENU :
			StateMenu::Update();
			break;
		case GAME :
			StateGame::Update();
			break;
		case QUIT :
			break;
	}
}

void StateMachine::StateDisplay(sf::RenderWindow& _window)
{
	//_window.clear();

	switch (m_CurrentState)
	{
		case MENU :
			StateMenu::Display(_window);
			break;
		case GAME :
			StateGame::Display(_window);
			break;
		case QUIT :
			_window.close();
			break;
	}
	_window.display();
}