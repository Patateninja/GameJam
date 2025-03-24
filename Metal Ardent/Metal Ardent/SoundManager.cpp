#include "SoundManager.hpp"
#include <filesystem>
#include <fstream>

namespace
{
	std::map<std::string, sf::SoundBuffer> soundBuffers;
	std::map<std::string, sf::Sound> sounds;
	std::map<std::string, sf::Music> music;
	std::vector<sf::Sound> multiSounds;
	std::vector<sf::SoundBuffer> multiBuffer;
	std::string currentMusic;
	std::string futureMusic;
	int musicVolume = 50;
	int soundVolume = 50;
}

void Sound::InitSoundManager()
{
	std::string path = "../Ressources/Option.txt";

	multiSounds.reserve(NUM_SOUNDS);
	multiBuffer.reserve(NUM_SOUNDS);

	if (std::filesystem::exists(path) == true)
	{
		//lit le fichier option.txt et récupère les volumes
		std::ifstream file(path);
		if (file.is_open())
		{
			std::string line;
			while (std::getline(file, line))
			{
				if (line.find("MusicVolume") != std::string::npos)
				{
					musicVolume = std::stoi(line.substr(line.find(" ") + 1));
				}
				if (line.find("SoundVolume") != std::string::npos)
				{
					soundVolume = std::stoi(line.substr(line.find(" ") + 1));
				}
			}
		}
	} 

	path = "../Ressources/Sounds/";
	std::string extension = ".ogg";

	//cherche les fichiers dans le dossier path et les ajoute dans soundBuffers et sounds avec leur nom en clé
	for (const auto& entry : std::filesystem::directory_iterator(path))
	{
		std::string name = entry.path().filename().string();
		name = name.substr(0, name.find(extension));
		sf::SoundBuffer buffer;
		buffer.loadFromFile(path + name + extension);
		soundBuffers[name] = buffer;
		sf::Sound sound;
		sound.setBuffer(soundBuffers[name]);
		sounds[name] = sound;
		sounds[name].setVolume(soundVolume);
	}

	path = "../Ressources/Music/";

	//cherche les fichiers dans le dossier path et les ajoute dans music avec leur nom en clé
	for (const auto& entry : std::filesystem::directory_iterator(path))
	{
		std::string name = entry.path().filename().string();
		name = name.substr(0, name.find(extension));
		music[name].openFromFile(path + name + extension);
		music[name].setVolume(musicVolume);
		music[name].setLoop(true);
	}
}

void Sound::getOption(int& _musicVolume, int& _soundVolume)
{
	_musicVolume = musicVolume;
	_soundVolume = soundVolume;
}

void Sound::SaveOption()
{
	std::string path = "../Ressources/Option.txt";
	std::ofstream file(path);
	if (file.is_open())
	{
		file << "MusicVolume " << musicVolume << std::endl;
		file << "SoundVolume " << soundVolume << std::endl;
	}
}

void Sound::PlaySound(std::string name)
{
	if (sounds.find(name) != sounds.end())
	{
		if (sounds[name].getStatus() == sf::Sound::Playing)
		{
			multiBuffer.push_back(soundBuffers[name]);
			multiBuffer.back().loadFromFile("../Ressources/Sounds/" + name + ".ogg");
			multiSounds.push_back(sf::Sound());
			multiSounds.back().setBuffer(multiBuffer.back());
			multiSounds.back().setVolume(soundVolume);
			multiSounds.back().play();
		}
		sounds[name].play();
	}
}

void Sound::PlayMusic(std::string name)
{
	if (music.find(name) != music.end())
	{
		if (currentMusic != "")
		{
			if (music[currentMusic].getStatus() == sf::Music::Playing)
			{
				music[currentMusic].stop();
			}
		}
		music[name].play();
		currentMusic = name;
	}
}

void Sound::StopMusic(std::string name)
{
	if (music.find(name) != music.end())
	{
		music[name].stop();
	}
}

void Sound::StopAllMusic()
{
	for (auto& m : music)
	{
		m.second.stop();
	}
}

void Sound::setFutureMusic(std::string name)
{
	music[currentMusic].setLoop(false);
	futureMusic = name;
}

void Sound::changeMusic()
{
	if (currentMusic != futureMusic)
	{
		StopMusic(currentMusic);
		PlayMusic(futureMusic);
	}
}

void Sound::updateMusic()
{

	for (int i = 0; i < multiSounds.size(); i++)
	{
		if (multiSounds[i].getStatus() == sf::Sound::Stopped)
		{
			multiSounds.erase(multiSounds.begin() + i);
			multiBuffer.erase(multiBuffer.begin() + i);
		}
	}


	if (music[currentMusic].getStatus() == sf::Music::Stopped && futureMusic != "")
	{
		music[currentMusic].stop();
		music[currentMusic].setLoop(true);
		PlayMusic(futureMusic);
		currentMusic = futureMusic;
		futureMusic = "";
	}
}

void Sound::changeMusicVolume(float _volume)
{
	musicVolume = _volume;
	for (auto& m : music)
	{
		m.second.setVolume(musicVolume);
	}
}

void Sound::changeSoundVolume(float _volume)
{
	soundVolume = _volume;
	for (auto& s : sounds)
	{
		s.second.setVolume(soundVolume);
	}
}