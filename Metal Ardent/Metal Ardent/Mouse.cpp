#include "Mouse.hpp"

namespace
{
	sf::Vector2i m_mousePos;
	sf::Vector2f m_relativeMousePos;
}

void Mouse::updateMousePosition(sf::RenderWindow& _window)
{
	m_mousePos = sf::Mouse::getPosition();
	m_relativeMousePos = _window.mapPixelToCoords(m_mousePos);
}

sf::Vector2f Mouse::getMousePos()
{
	return sf::Vector2f(m_mousePos.x, m_mousePos.y);
}

sf::Vector2i Mouse::getMousePosI()
{
	return m_mousePos;
}

sf::Vector2f Mouse::getRelativeMousePos()
{
	return m_relativeMousePos;
}

sf::Vector2i Mouse::getRelativeMousePosI()
{
	return sf::Vector2i(m_relativeMousePos.x, m_relativeMousePos.y);
}
