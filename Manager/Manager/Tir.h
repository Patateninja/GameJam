#pragma once
#include "tools.h"

enum TypeTir 
{
    PETIT,
    GROS
};

void initTir();

class Tir 
{
public:
    Tir(float angle, sf::Vector2f position, TypeTir type);
    void Update();
    void Display(sf::RenderWindow& window);
    bool isAlive() const;
    void setAlive(bool alive);

private:
    sf::Vector2f m_position;
    sf::Vector2f m_velocity;
    float m_angle;
    TypeTir m_type;
    bool m_alive;
};
