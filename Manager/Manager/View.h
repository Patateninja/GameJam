#pragma once
#include "Tools.h"

class Window;

class View
{
	private:
		sf::View m_view;
		sf::Vector2f m_position;
		sf::Vector2f m_size;
		sf::Vector2f m_center;

	public:

		View();
		View(Window& _window);
		View(sf::Vector2f _size);
		View(sf::Vector2f _size, sf::Vector2f _center);


		void setPosCenter(sf::Vector2f _center);
		void setPosition(sf::Vector2f _position);
		void setsize(sf::Vector2f _size) { m_size = _size; }
		void setView(Window& _window);
		void copyThisView(sf::View _view);

		const sf::View& getView() { return m_view; }
		const sf::Vector2f& getPosition() { return m_position; }
		const sf::Vector2f& getSize() { return m_size; }
		const sf::Vector2f& getCenter() { return m_center; }
};

