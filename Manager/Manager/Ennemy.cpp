#include "Ennemy.h"
#include "Math.h"

namespace
{
	sf::RectangleShape m_shape;
	sf::Texture m_texture;
	sf::Vector2f m_target;
}

Ennemy::Ennemy(sf::Vector2f pos, EnemyClass type)
{
	m_pos = pos;
	m_class = type;
	m_pv = 100;
	m_velocity = sf::Vector2f(0, 0);
	angle = 0;
	m_shape.setSize(sf::Vector2f(50, 50));
	m_shape.setOrigin(m_shape.getSize() / 2.f);
	m_shape.setFillColor(sf::Color::Green);
}

Ennemy::~Ennemy()
{
}

void Ennemy::update()
{
	m_target = Mouse::getRelativeMousePos(); //TODO : get target from player
	m_velocity = Math::normalize(m_target - m_pos) * 100.f * getDeltaTime();
	m_pos += m_velocity * getDeltaTime() * 100.f;
	angle = Math::getAngle(m_pos, m_target);
}

bool Ennemy::IsColliding(const sf::IntRect rect)
{
	return m_shape.getGlobalBounds().intersects(sf::FloatRect(rect.left, rect.top, rect.width, rect.height));
}

void Ennemy::display(sf::RenderWindow& window)
{
	m_shape.setPosition(m_pos);
	m_shape.setRotation(angle);
	window.draw(m_shape);
}
