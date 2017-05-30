#include "AudioManager.h"

AudioManager audioManager;

AudioManager::AudioManager()
{
}


AudioManager::~AudioManager()
{
	al_destroy_sample(music);
}

void AudioManager::New()
{
	music = al_load_sample(AUDIO_MUSIC);
}

void AudioManager::PlayMusic()
{
	al_play_sample(music, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
}
