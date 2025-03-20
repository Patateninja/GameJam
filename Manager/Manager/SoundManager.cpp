#include "SoundManager.h"
#include <filesystem>

namespace
{
	std::map<std::string, sf::SoundBuffer> soundBuffers;
	std::map<std::string, sf::Sound> sounds;
	std::map<std::string, sf::Music> music;
	std::string currentMusic;
	std::string futureMusic;

}

void Sound::LoadSounds()
{
	std::string path = "Ressources/Sounds/";
	std::string extension = ".ogg";

	
}
