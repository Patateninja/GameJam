#pragma once
#include "tools.h"

void InitTir();

enum TypeTir
{
	PETIT,
	GROS
};

class Tir
{
private:
	int m_vie;
	TypeTir m_type;
	sf::Vector2f m_posTir;
	sf::Vector2f m_velocityTir;
	float m_angleTir;

public:
	Tir() {};
	Tir(float _angleTir, sf::Vector2f _posTir, TypeTir _type);
	~Tir() {};

	void UpdateTir();
	void DisplayTir(sf::RenderWindow& _window);

	//getter
	inline int getTirVie() { return m_vie; };

	inline TypeTir getTirType() { return m_type; };

	inline sf::Vector2f getTirPos() { return m_posTir; };

	inline sf::Vector2f getTirVelocity() { return m_velocityTir; };

	inline float getTirAngle() { return m_angleTir; };

	//setter
	inline int setTirVie(const int _vie) { m_vie = _vie; };

	inline TypeTir setTirType(const TypeTir _type) { m_type = _type; };

	inline sf::Vector2f setTirPos(const sf::Vector2f _posTir) { m_posTir = _posTir; };

	inline sf::Vector2f setTirVelocity(const sf::Vector2f _velocityTir) { m_velocityTir = _velocityTir; };

	inline float setTirAngle(const float _angleTir) { m_angleTir = _angleTir; };

};

