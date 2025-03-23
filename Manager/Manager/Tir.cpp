#include "Tir.h"
#include "Math.h"

namespace
{
	sf::Texture m_texturePetit;
	sf::Texture m_textureGros;
	sf::Sprite m_spritePetit;
	sf::Sprite m_spriteGros;

	std::list<Tir> tirs; //TODO ask why Vector
}

std::list<Tir>& getTirList() { return tirs; }

void initTir()
{
	if (!m_texturePetit.loadFromFile("../Ressources/Textures/SmallBaballe.png"))
		throw std::runtime_error("UwU");
	if (!m_textureGros.loadFromFile("../Ressources/Textures/BigBaballe.png"))
		throw std::runtime_error("UwU");
	m_spritePetit.setTexture(m_texturePetit);
	m_spriteGros.setTexture(m_textureGros);
	m_spritePetit.setTextureRect(sf::IntRect(0,0,10,21));
	m_spritePetit.setOrigin(m_spritePetit.getGlobalBounds().getSize() * 0.5f);
	m_spriteGros.setOrigin(m_spriteGros.getGlobalBounds().getSize() * 0.5f);
	m_spriteGros.setScale(0.2f, 0.2f);
}

Tir::Tir(float angle, sf::Vector2f position, TypeTir type)
	: m_position(position), m_angle(angle), m_type(type), m_alive(true), animTimer(0.f), lifeTimer(1.f) {

	// Calculer la direction du tir en fonction de l'angle
	float radians = m_angle * DEG2RAD;
	switch (m_type)
	{
		case PETIT:
			m_velocity.x = std::sin(radians) * 600.0f;  // Vitesse sur X
			m_velocity.y = -std::cos(radians) * 600.0f; // Vitesse sur Y
			lifeTimer = 0.6f;
			break;
		case GROS:
			m_velocity.x = std::sin(radians) * 500.0f;  // Vitesse sur X
			m_velocity.y = -std::cos(radians) * 500.0f; // Vitesse sur Y
			lifeTimer = 2.5f;
			break;
	}
 }

void Tir::Update() {
	if (!m_alive) return;
	if ((lifeTimer -= getDeltaTime()) < 0.f) m_alive = false;

	// Déplacer le tir
	m_position += m_velocity * getDeltaTime();
}

void Tir::Display(sf::RenderWindow& window) {
	if (!m_alive) return;
	if (m_type == TypeTir::PETIT) {
		animTimer += getDeltaTime();
		if (animTimer > 0.1f)
		{
			frameX = (frameX + 1) % 14;
			m_spritePetit.setTextureRect(sf::IntRect(frameX * 10, 0, 10, 21));

			animTimer = 0.f;
		}
		m_spritePetit.setPosition(m_position);
		m_spritePetit.setRotation(m_angle);
		window.draw(m_spritePetit);
	}
	else {
		m_spriteGros.setPosition(m_position);
		m_spriteGros.setRotation(m_angle);
		window.draw(m_spriteGros);
	}
}

bool Tir::isAlive() const {
	return m_alive;
}

void Tir::destroyIfDead()
{
	if (!m_alive) Tir::~Tir();
}