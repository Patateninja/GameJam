#include "Map.h"
#include <thread>

class Chunk
{
public:
	Chunk(bool haveToGenerate = true, sf::Vector2f tile = sf::Vector2f(0, 0));
	~Chunk();

	//getters
	sf::Vector2f getTile() { return m_Tile; }
	std::list<sf::Vector2f> getDiversities() { return m_Diversities; }
	std::list<sf::Vector2f> getObstacles() { return m_Obstacles; }

	//setters
	void setTile(sf::Vector2f tile) { m_Tile = tile; }
	void setDiversities(std::list<sf::Vector2f> diversities) { m_Diversities = diversities; }
	void setObstacles(std::list<sf::Vector2f> obstacles) { m_Obstacles = obstacles; }

	//adders
	void addDiversity(sf::Vector2f diversity) { m_Diversities.push_back(diversity); }
	void addObstacle(sf::Vector2f obstacle) { m_Obstacles.push_back(obstacle); }

	bool operator==(const Chunk& chunk)
	{
		if (m_Tile == chunk.m_Tile)
		{
			return true;
		}
		return false;
	}

private:
	sf::Vector2f m_Tile;
	std::list<sf::Vector2f> m_Diversities;
	std::list<sf::Vector2f> m_Obstacles;
};

Chunk::Chunk(bool _hasToGenerate, sf::Vector2f tile)
{
	if (_hasToGenerate)
	{
		int ChunkX = tile.x;
		int ChunkY = tile.y;

		m_Tile = sf::Vector2f(ChunkX, ChunkY);

		for (int i = 0; i < 10; i++)
		{
			int random = rand() % 2;

			if (random == 0)
			{
				sf::Vector2f diversity = sf::Vector2f(rand() % 1320 + 300, rand() % 480 + 300);

				//test if the diversity is not on the corner of the map (300px away from the edge) (the map is not 1920x1080 its relative to the player position)
				diversity.x += ChunkX * 1920;
				diversity.y += ChunkY * 1080;


				bool isOnObstacle = false;
				//verify if the diversity is not on the same place at 300px as an obstacle and if it's not on the same place at 300px as another diversity
				for (auto& obstacle : m_Obstacles)
				{
					if (Math::distance(diversity, obstacle) < 300)
					{
						isOnObstacle = true;
					}
				}
				for (auto& diversity : m_Diversities)
				{
					if (Math::distance(diversity, diversity) < 100)
					{
						isOnObstacle = true;
					}
				}
				if (!isOnObstacle)
				{
					m_Diversities.push_back(diversity);
				}
			}
			else
			{
				sf::Vector2f obstacle = sf::Vector2f(rand() % 1320 + 300, rand() % 480 + 300);

				//test if the obstacle is not on the corner of the map (300px away from the edge) (the map is not 1920x1080 its relative to the player position)
				obstacle.x += ChunkX * 1920;
				obstacle.y += ChunkY * 1080;

				bool isOnDiversity = false;
				//verify if the obstacle is not on the same place at 300px as an obstacle and if it's not on the same place at 300px as another diversity
				for (auto& obstacle : m_Obstacles)
				{
					if (Math::distance(obstacle, obstacle) < 300)
					{
						isOnDiversity = true;
					}
				}
				for (auto& diversity : m_Diversities)
				{
					if (Math::distance(obstacle, diversity) < 100)
					{
						isOnDiversity = true;
					}
				}
				if (!isOnDiversity)
				{
					m_Obstacles.push_back(obstacle);
				}
			}
		}
	}
}

Chunk::~Chunk()
{
}

namespace
{
	std::list<Chunk> m_ListChunks;
	std::list<Chunk> m_oldChunks;

	bool anotherChunkIsLoading()
	{
		for (auto& chunk : m_ListChunks)
		{
			bool isOld = false;
			for (auto& oldChunk : m_oldChunks)
			{
				if (chunk == oldChunk)
				{
					isOld = true;
				}
			}
			if (!isOld)
			{
				return true;
			}
		}
		return false;
	}

	void actualizeChunks()
	{
		//to change
		sf::Vector2f playerPos = sf::Vector2f(0, 0);
		int ChunkX = playerPos.x / 1920;
		int ChunkY = playerPos.y / 1080;

		m_ListChunks.push_back(Chunk(false ,sf::Vector2f(ChunkX , ChunkY )));
		m_ListChunks.push_back(Chunk(false ,sf::Vector2f(ChunkX + 1, ChunkY )));
		m_ListChunks.push_back(Chunk(false, sf::Vector2f(ChunkX, ChunkY + 1)));
		m_ListChunks.push_back(Chunk(false, sf::Vector2f(ChunkX + 1, ChunkY + 1)));
		m_ListChunks.push_back(Chunk(false, sf::Vector2f(ChunkX - 1, ChunkY)));
		m_ListChunks.push_back(Chunk(false, sf::Vector2f(ChunkX, ChunkY - 1)));
		m_ListChunks.push_back(Chunk(false, sf::Vector2f(ChunkX - 1, ChunkY - 1)));
		m_ListChunks.push_back(Chunk(false, sf::Vector2f(ChunkX + 1, ChunkY - 1)));
		m_ListChunks.push_back(Chunk(false, sf::Vector2f(ChunkX - 1, ChunkY + 1)));

	}

	void loadChunk()
	{
		if (anotherChunkIsLoading())
		{
			//pour chaque chunk qui n'est pas dans la liste des anciens chunks on le crée avec un thread
			for (auto& chunk : m_ListChunks)
			{
				bool isOld = false;
				for (auto& oldChunk : m_oldChunks)
				{
					if (chunk == oldChunk)
					{
						isOld = true;
					}
				}
				if (!isOld)
				{
					std::thread t(generateChunk, chunk.getTile());
					t.detach();
				}
			}
		}
	}

	void generateChunk(sf::Vector2f m_pos)
	{
		Chunk chunk(true, m_pos);
		m_oldChunks.push_back(chunk);
	}
}