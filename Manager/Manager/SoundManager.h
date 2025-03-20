#pragma once
#include "SFML/audio.hpp"
#include <iostream>
#include <string>
#include <map>
#define NUM_SOUNDS 10 

namespace Sound 
{

	void InitSoundManager();
	void getOption(int& _musicVolume, int& _soundVolume);
	void SaveOption();
	void PlaySound(std::string _name);

	void PlayMusic(std::string _name);
	void StopMusic(std::string _name);
	void StopAllMusic();
	void setFutureMusic(std::string _music);
	void changeMusic();

	void updateMusic();
	void changeMusicVolume(float _volume);
	void changeSoundVolume(float _volume);

}