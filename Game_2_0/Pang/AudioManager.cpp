#include "AudioManager.h"
#include <stdio.h>

AudioManager audioManager;

AudioManager::AudioManager()
{
}

AudioManager::~AudioManager()
{
	//al_destroy_sample(m_music);

	for (int i = 0; i < AUDIO_SOUNDS_LENGHT; i++)
	{
		//al_destroy_sample(m_sounds[i]);
	}
}

void AudioManager::New()
{
	m_music = al_load_sample(AUDIO_MUSIC);

	for (int i = 0; i < AUDIO_SOUNDS_LENGHT; i++)
	{
		m_sounds[i] = al_load_sample(AUDIO_SOUND[(Sounds)i]);
	}
}

void AudioManager::PlayMusic()
{
	al_play_sample(m_music, 0.1f, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
}

void AudioManager::PlaySound(Sounds sound)
{
	al_play_sample(m_sounds[(int)sound], 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
}

void AudioManager::StopMusic()
{
}
