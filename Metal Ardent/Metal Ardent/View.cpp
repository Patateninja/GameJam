#include "View.hpp"
#include "Window.hpp"

View::View()
{
	m_size = sf::Vector2f(800.0f, 600.0f);
	m_center = sf::Vector2f(960.0f, 540.0f);
	m_position = sf::Vector2f(0.0f, 0.0f);
	m_view.setSize(m_size);
	m_view.setCenter(m_center);
}

View::View(Window& _window)
{
	m_size = sf::Vector2f(_window.getSize().x, _window.getSize().y);
	m_center = sf::Vector2f(_window.getSize().x / 2, _window.getSize().y / 2);
	m_position = m_center - (m_size / 2.0f);
	m_view.setSize(m_size);
	m_view.setCenter(m_center);
}

View::View(sf::Vector2f _size)
{
	m_size = _size;
	m_center = sf::Vector2f(_size.x / 2, _size.y / 2);
	m_position = m_center - (m_size / 2.0f);
	m_view.setSize(m_size);
	m_view.setCenter(m_center);
}

View::View(sf::Vector2f _size, sf::Vector2f _center)
{
	m_size = _size;
	m_center = _center;
	m_position = m_center - (m_size / 2.0f);
	m_view.setSize(m_size);
	m_view.setCenter(m_center);

}

void View::setPosCenter(sf::Vector2f _center)
{
	m_center = _center;
	m_position = m_center - (m_size / 2.0f);
	m_view.setCenter(m_center);
}

void View::setPosition(sf::Vector2f _position)
{
	m_position = _position;
	m_center = m_position + (m_size / 2.0f);
	m_view.setCenter(m_center);
}

void View::setView(Window& _window)
{
	m_size = sf::Vector2f(_window.getSize().x, _window.getSize().y);
	m_center = sf::Vector2f(_window.getSize().x / 2, _window.getSize().y / 2);
	m_position = sf::Vector2f(0.0f, 0.0f);
	m_view.setSize(m_size);
	m_view.setCenter(m_center);
}

void View::copyThisView(sf::View _view)
{
	m_view = _view;
	m_size = m_view.getSize();
	m_center = m_view.getCenter();
	m_position = m_view.getCenter() - (m_view.getSize() / 2.0f);
}