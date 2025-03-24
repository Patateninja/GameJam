#include "Button.hpp"

Button::Button(Action _action, sf::Vector2f _pos, ActualMenu _menu)
{
	this->m_Rect = sf::RectangleShape(sf::Vector2f(250.f, 75.f));
	this->SetRectPos(_pos);
	this->m_Selected = false;
	this->m_Action = _action;
	_menu.Add(this);
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

void ActualMenu::Add(Button* _button)
{
	this->ButtonList.push_back(_button);
}

Button* ActualMenu::Get(int _index)
{
	if (_index < this->ButtonList.size())
	{
		return this->ButtonList[this->selectedButton];
	}
	
	return nullptr;
}

int ActualMenu::GetSelectedButton()
{
	return this->selectedButton;
}
	
std::vector<Button*> ActualMenu::GetList()
{
	return this->ButtonList;
}

Action ActualMenu::Update()
{
	if (Keys::isUpPressed)
	{
		this->selectedButton--;
		if (this->selectedButton < 0)
		{
			this->selectedButton = this->ButtonList.size() - 1;
		}
	}
	if (Keys::isDownPressed)
	{
		this->selectedButton++;
		if (this->selectedButton > this->ButtonList.size() - 1)
		{
			this->selectedButton = 0;
		}
	}

	for (Button* button : this->ButtonList)
	{
		if (button == this->ButtonList[this->selectedButton])
		{
			button->SetSelected(true);
		}
		else
		{
			button->SetSelected(false);
		}
	}


	if (Keys::isInteractPressed)
	{
		return this->ButtonList[this->selectedButton]->GetAction();
	}
	else
	{
		return NOTHING;
	}
}

void ActualMenu::Display(sf::RenderWindow& _window)
{
	for (Button* button : this->ButtonList)
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