#pragma once
#include "SFML/audio.hpp"
#include <iostream>
#include <string>
#include <map>
#define NUM_SOUNDS 10 

namespace Sound 
{
	void LoadSounds();
	void PlaySound(std::string);
	void StopSound(std::string);
	void StopAllSounds();
	void SetVolume(std::string, float);
	
	void LoadMusic();
	void PlayMusic(std::string);
	void StopMusic(std::string);
	void StopAllMusic();
	void SetMusicVolume(std::string, float);
	void SetMusicLoop(std::string, bool);
	void setFutureMusic(std::string);
	void changeMusic();


}