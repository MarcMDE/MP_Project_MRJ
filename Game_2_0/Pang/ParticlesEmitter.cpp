#include "ParticlesEmitter.h"

ParticlesEmitter::ParticlesEmitter()
{
	m_particles = NULL;
}


ParticlesEmitter::~ParticlesEmitter()
{
	delete[] m_particles;
}

void ParticlesEmitter::New(Emitters type, Vector2 position, ALLEGRO_BITMAP * image)
{
	m_type = type;
	SetPosition(position);
	m_particles = new Particle[PARTICLES_LENGHT[m_type]];

	//for (int i = 0; i < PARTICLES_LENGHT[m_type]; i++) m_particles[i] = Particle(image);
	for (int i = 0; i < PARTICLES_LENGHT[m_type]; i++) m_particles[i].Construct(image);
}

void ParticlesEmitter::Burst()
{
	for (int i = 0; i < PARTICLES_LENGHT[m_type]; i++)
	{
		if (IsActive())
		{
			// TODO: CHECK RANDOM FUNCS!!!
			m_particles[i].New(
			GetPosition(),
			{GetRandomValue(PARTICLES_MIN_SPEED[m_type], PARTICLES_MAX_SPEED[m_type]) },
			{GetRandomValue(-1.0f, 1.0f), GetRandomValue(-0.5f, -1.0f)},
			{ GetRandomValue(PARTICLES_MIN_DURATION[m_type], PARTICLES_MAX_DURATION[m_type])}, 
			true
			);
		}
	}
}

void ParticlesEmitter::Update()
{
	if (IsActive())
	{
		for (int i = 0; i < PARTICLES_LENGHT[m_type]; i++)
		{
			m_particles[i].Update();
		}
	}
}

void ParticlesEmitter::Draw()
{
	if (IsDrawable())
	{
		for (int i = 0; i < PARTICLES_LENGHT[m_type]; i++)
		{
			m_particles[i].Draw();
		}
	}
}

void ParticlesEmitter::Reset()
{
	for (int i = 0; i < PARTICLES_LENGHT[m_type]; i++)
	{
		m_particles[i].Deactivate();
	}
}

bool ParticlesEmitter::IsAnyParticleActive()
{
	int i = 0;
	while (!m_particles[i].IsActive() && i < PARTICLES_LENGHT[m_type])
	{
		i++;
	}

	return i != PARTICLES_LENGHT[m_type];
}
