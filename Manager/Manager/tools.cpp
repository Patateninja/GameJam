#include "Tools.h"

namespace
{
    sf::Clock m_clock;
    float m_deltaTime;
}

float getDeltaTime()
{
    return m_deltaTime;
}


void updateDeltaTime()
{
    m_deltaTime = m_clock.restart().asSeconds();
    if (m_deltaTime > 0.1f)
        m_deltaTime = 0.1f;
}