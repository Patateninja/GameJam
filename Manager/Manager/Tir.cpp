#include "Tir.h"

namespace
{
    sf::Texture m_texturePetit;
    sf::Texture m_textureGros;
    sf::Sprite m_spritePetit;
    sf::Sprite m_spriteGros;
}

void initTir()
{
	if (!m_texturePetit.loadFromFile("../Ressources/Textures/Tir.png"))
		throw std::runtime_error("UwU");
	if (!m_textureGros.loadFromFile("../Ressources/Textures/Tir.png"))
		throw std::runtime_error("UwU");
	m_spritePetit.setTexture(m_texturePetit);
	m_spriteGros.setTexture(m_textureGros);
}

Tir::Tir(float angle, sf::Vector2f position, TypeTir type)
    : m_position(position), m_angle(angle), m_type(type), m_alive(true) {

    // Calculer la direction du tir en fonction de l'angle
    float radians = m_angle * 3.14159f / 180.f;
    m_velocity.x = std::sin(radians) * 400.0f;  // Vitesse sur X
    m_velocity.y = -std::cos(radians) * 400.0f; // Vitesse sur Y
}

void Tir::Update() {
    if (!m_alive) return;

    // Déplacer le tir
    m_position += m_velocity * getdeltaTime();

    // Vérifier si le tir est hors de l'écran
    if (m_position.x < 0 || m_position.x > 1920 || m_position.y < 0 || m_position.y > 1080) {
        m_alive = false;
    }
}

void Tir::Display(sf::RenderWindow& window) {
    if (!m_alive) return;
	if (m_type == TypeTir::PETIT) {
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

void Tir::setAlive(bool alive) {
    m_alive = alive;
}
