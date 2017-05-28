#pragma once

#include "Particle.h"
#include "GameConfig.h"
#include "GameObject.h"

using namespace GameConfig;

class ParticlesEmitter : public GameObject
{
private:
	Particle *m_particles;
	Emitters m_type;

public:
	ParticlesEmitter();
	~ParticlesEmitter();

	void New(Emitters type, Vector2 position, ALLEGRO_BITMAP * image);
	void Burst();
	void Update();
	void Draw();
	void Reset();
	bool IsAnyParticleActive();

};

