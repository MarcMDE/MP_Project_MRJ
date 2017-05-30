#pragma once
#include "allegro5/allegro.h"
#include "allegro5/allegro_audio.h"
#include "GameConfig.h"

using namespace GameConfig;

class AudioManager
{
private:
	ALLEGRO_SAMPLE *m_music = NULL;
	ALLEGRO_SAMPLE *m_sounds[AUDIO_SOUNDS_LENGHT];
public:
	AudioManager();
	~AudioManager();

	void New();
	void PlayMusic();
	void PlaySound(Sounds sound);
	void StopMusic();
};

extern AudioManager audioManager;
