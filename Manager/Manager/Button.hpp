#pragma once
#include "SFML/Graphics.hpp"
#include "Tools.h"
#include <vector>

class ActualMenu;

typedef enum Action
{
	TO_MENU,
	TO_GAME,
	TO_OPTION,
	TO_QUIT,
	NOTHING,
} Action;

class Button
{
	private :
		sf::RectangleShape m_Rect;
		Action m_Action;
		bool m_Selected;
	public :
		Button(Action _action, sf::Vector2f _pos, ActualMenu _menu);
		~Button();

		sf::RectangleShape& GetRect() { return this->m_Rect; };
		Action GetAction() { return this->m_Action; };
		bool GetSelected() { return this->m_Selected; };

		void SetRectPos(sf::Vector2f _pos);
		void SetRectSize(sf::Vector2f _size);
		void SetSelected(bool _selected);
};

class ActualMenu
{
	private :
		sf::Clock m_Timer;
		int selectedButton = 0;
		std::vector<Button*> ButtonList;
	public :
		ActualMenu() = default;
		~ActualMenu() = default;

		void Add(Button* _button);
		Button* Get(int _index);
		std::vector<Button*> GetList();

		Action Update();
		void Display(sf::RenderWindow& _window);
};