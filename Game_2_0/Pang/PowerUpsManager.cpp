#include "PowerUpsManager.h"
#include <stdio.h>

PowerUpsManager powerUpsManager;

PowerUpsManager::PowerUpsManager()
{
}


PowerUpsManager::~PowerUpsManager()
{
}

void PowerUpsManager::New()
{
	for (int i = 0; i < POWERUPS_LENGHT; i++)
	{
		m_powerUps[i].New((PowerUps)i);
		m_powerUps[i].Deactivate();
		m_activeEffects[i] = false;
		m_paralysisCounter = 0;
	}
}

void PowerUpsManager::SpawnRandomPowerUp(Vector2 position)
{
	//printf("SPAWN PU?\n");
	if (GetRandomValue(0, 100) <= POWERUPS_SPAWNPROB)
	{
		int type = GetRandomValue(0, POWERUPS_LENGHT - 1);
		if (!m_powerUps[type].IsActive())
		{
			//m_activeEffects[type] = true;
			m_powerUps[type].Activate();
			m_powerUps[type].Spawn(position);
			printf("PU SPAWNED\n");
		}
	}
}

void PowerUpsManager::Update()
{
	if (m_paralysisCounter > 0)
	{
		m_paralysisCounter--;
	}
	else if (m_activeEffects[PARALYSIS])
	{
		m_activeEffects[PARALYSIS] = false;
	}

	//printf("STOP: %i\n", (int)m_activeEffects[PARALYSIS]);

	for (int i = 0; i < POWERUPS_LENGHT; i++)
	{
		m_powerUps[i].Update();
	}
}

void PowerUpsManager::ActivateEffect(PowerUps type)
{
	//printf("SPAWN_POWER_UP\n");
	m_activeEffects[(int)type] = true;

	printf("EFFECT: %i\n", (int)type);

	if (type == PARALYSIS)
	{
		printf("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n");
		m_paralysisCounter += POWERUPS_PARALYISIS_DURATION;
	}
}

bool PowerUpsManager::IsEffectActive(PowerUps type)
{
	return m_activeEffects[(int)type];
}

void PowerUpsManager::DeactivateEffect(PowerUps type)
{
	m_activeEffects[(int)type] = false;
}

void PowerUpsManager::CheckPlayerCollision(AABB collider)
{
	for (int i = 0; i < POWERUPS_LENGHT; i++)
	{
		if (m_powerUps[i].IsActive())
		{
			if (m_powerUps[i].CheckPlayerCollision(collider))
			{
				ActivateEffect((PowerUps)i);
			}
		}
	}
}

void PowerUpsManager::Draw()
{
	for (int i = 0; i < POWERUPS_LENGHT; i++)
	{
		m_powerUps[i].Draw();
	}
}

void PowerUpsManager::Reset()
{
	for (int i = 0; i < POWERUPS_LENGHT; i++)
	{
		m_activeEffects[i] = false;
	}
	m_paralysisCounter = 0;
}
