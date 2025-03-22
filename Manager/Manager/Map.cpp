#include "Map.h"

namespace
{
	std::list<sf::Vector2f> m_Diversities;
	std::list<sf::Vector2f> m_Obstacles;
	std::list<sf::Vector2f> m_ListChunks;
	std::list<sf::Vector2f> m_oldChunks;

	bool anotherChunkIsLoading()
	{
		for (auto& chunk : m_ListChunks)
		{
			for (auto& oldChunk : m_oldChunks)
			{
				if (chunk != oldChunk)
				{
					return true;
				}
			}
		}
		return false;
	}

	void actualizeChunks()
	{
		sf::Vector2f playerPos = sf::Vector2f(0, 0);
		for (auto& chunk : m_ListChunks)
		{
			if (chunk.x < playerPos.x - 1000 || chunk.x > playerPos.x + 1000 || chunk.y < playerPos.y - 1000 || chunk.y > playerPos.y + 1000)
			{
				m_ListChunks.remove(chunk);
			}
		}
		
	}

	void loadChunk()
	{
		if (anotherChunkIsLoading())
		{
			m_oldChunks = m_ListChunks;

		}
	}
}