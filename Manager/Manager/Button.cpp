#include "Button.hpp"

Button::Button(Action _action, sf::Vector2f _pos)
{
	this->m_Rect = sf::RectangleShape(sf::Vector2f(250.f, 75.f));
	this->SetRectPos(_pos);
	this->m_Selected = false;
	this->m_Action = _action;
	ButtonList::Add(this);
}

Button::~Button()
{

}

void Button::SetRectPos(sf::Vector2f _pos)
{
	this->m_Rect.setPosition(_pos);
}

void Button::SetRectSize(sf::Vector2f _size)
{
	this->m_Rect.setPosition(_size);
}

void Button::SetSelected(bool _selected)
{
	this->m_Selected = _selected;
}

/////////////////////////////////////////////////////////////////////

void ButtonList::Add(Button* _button)
{
	ButtonList::ButtonList.push_back(_button);
}

Button* ButtonList::Get(int _index)
{
	if (_index < ButtonList::ButtonList.size())
	{
		return ButtonList::ButtonList[ButtonList::selectedButton];
	}
	
	return nullptr;
}

Action ButtonList::Update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		ButtonList::selectedButton--;
		if (ButtonList::selectedButton < 0)
		{
			ButtonList::selectedButton = ButtonList::ButtonList.size() - 1;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		ButtonList::selectedButton++;
		if (ButtonList::selectedButton > ButtonList::ButtonList.size() - 1)
		{
			ButtonList::selectedButton = 0;
		}
	}


	for (Button* button : ButtonList::ButtonList)
	{
		if (button == ButtonList::ButtonList[ButtonList::selectedButton])
		{
			button->SetSelected(true);
		}
		else
		{
			button->SetSelected(false);
		}
	}
	

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		return ButtonList::ButtonList[ButtonList::selectedButton]->GetAction();
	}
	else
	{
		return NOTHING;
	}
}

void ButtonList::Display(sf::RenderWindow& _window)
{
	for (Button* button : ButtonList::ButtonList)
	{
		if (button->GetSelected())
		{
			button->GetRect().setFillColor(sf::Color::Blue);
		}
		else
		{
			button->GetRect().setFillColor(sf::Color::Green);
		}

		_window.draw(button->GetRect());
	}
}