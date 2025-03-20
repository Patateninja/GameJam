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
			Menu::DeInit();
			break;
		case GAME:
			Game::DeInit();
			break;
		}

		m_CurrentState = _state;

		switch (m_CurrentState)
		{
		case MENU:
			Menu::Init();
			break;
		case GAME:
			Game::Init();
			break;
		}
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
			Menu::Update();
			break;
		case GAME :
			Game::Update();
			break;
		case QUIT :
			break;
	}
}

void StateMachine::StateDisplay(sf::RenderWindow& _window)
{
	switch (m_CurrentState)
	{
		case MENU :
			Menu::Display(_window);
			break;
		case GAME :
			Game::Display(_window);
			break;
	}
}