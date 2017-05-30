#pragma once
#include "allegro5/allegro.h"
#include "allegro5/allegro_audio.h"
#include "GameConfig.h"

using namespace GameConfig;

class AudioManager
{
private:
	ALLEGRO_SAMPLE *music = NULL;
public:
	AudioManager();
	~AudioManager();

	void New();
	void PlayMusic();
};

extern AudioManager audioManager;
