#pragma once
#include "GameObject.h"
#include "Sprite.h"
#include "AABB.h"
#include "GameConfig.h"
#include "Player.h"
#include "ParticlesEmitter.h"

using namespace GameConfig;

class PowerUp : public GameObject
{
private: 
	Sprite m_sprite;
	AABB m_collider;
	Vector2 m_velocity;
	bool m_isGrounded;
	PowerUps m_type;
	int m_counter;
	ParticlesEmitter m_emitter;

public:
	PowerUp();
	~PowerUp();

	void New(PowerUps type);
	void Spawn(Vector2 position);
	void Update();
	void Draw();
	bool CheckPlayerCollision(AABB c);
	PowerUps GetType();
};

