#pragma once
#include "ResourceManager.h"
#include <SFML/Audio.hpp>

class AudioManager : ResourceManager<AudioManager, sf::SoundBuffer>
{
public:
	AudioManager(): ResourceManager("audio.cfg"){}

	sf::SoundBuffer* Load(const std::string& lPath)
	{
		sf::SoundBuffer* newSound = new sf::SoundBuffer;
		if (!newSound->loadFromFile(lPath))
		{
			std::cout << "Error: Unable to open " << lPath << std::endl;
			delete newSound;
			return nullptr;
		}
		return newSound;
	}
};