#pragma once
#include "PowerUp.h"
//#include "GameUtils2D.h"

using namespace GameUtils2D;

class PowerUpsManager
{
private:
	PowerUp m_powerUps[POWERUPS_LENGHT];
	bool m_activeEffects[POWERUPS_LENGHT];
	int m_paralysisCounter;

public:
	PowerUpsManager();
	~PowerUpsManager();

	void New();
	void SpawnRandomPowerUp(Vector2 position);
	void Update();
	void ActivateEffect(PowerUps type);
	bool IsEffectActive(PowerUps type);
	void DeactivateEffect(PowerUps type);
	void CheckPlayerCollision(AABB collider);
	void Draw();
	void Reset();
};

extern PowerUpsManager powerUpsManager;