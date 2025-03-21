#pragma once
#include "SFML/Graphics.hpp"
#include <vector>

typedef enum Action
{
	TO_MENU,
	TO_GAME,
	TO_OPTION,
	TO_QUIT,
	NOTHING,
};

class Button
{
	private :
		sf::RectangleShape m_Rect;
		Action m_Action;
		bool m_Selected;
	public :
		Button(Action _action, sf::Vector2f _pos);
		~Button();

		sf::RectangleShape GetRect() { return this->m_Rect; };
		Action GetAction() { return this->m_Action; };
		bool GetSelected() { return this->m_Selected; };

		void SetRectPos(sf::Vector2f _pos);
		void SetRectSize(sf::Vector2f _size);
		void SetSelected(bool _selected);
};

namespace ButtonList
{
	int selectedButton;
	std::vector<Button*> ButtonList;
	void Add(Button* _button);
	Button* Get(int _index);
	Action Update();
	void Display(sf::RenderWindow& _window);
}