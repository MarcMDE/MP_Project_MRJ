#include "Pang.h"
#include <stdio.h>


Pang::Pang()
{
}

Pang::~Pang()
{
}

void Pang::Initialize()
{
	srand(time(NULL));

	player.New(0);
	levelManager.New(LEVEL_01);
	levelManager.StartNewLevel(LEVEL_01);
	pEmitter.New(TEST, { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 }, al_load_bitmap(PARTICLES_SPRITE[TEST]));
	pU.New(HEALTH_UP);
	powerUpsManager.New();
	m_highscores.New();
	m_highscores.ReadHighscores();

	player.Update(); // Check why needed. // Temp

	m_isPaused = false;
	pauseSprite.New({ SCREEN_WIDTH, SCREEN_HEIGHT }, al_map_rgba( 120, 120, 120, 25));
}

void Pang::Update()
{
	/*
	anim.Update();

	if (input.IsKeyDown((int)ALLEGRO_KEY_A)) auxPosition.x-=2;
	else if (input.IsKeyDown((int)ALLEGRO_KEY_D)) auxPosition.x+=2;
	if (input.IsKeyDown((int)ALLEGRO_KEY_W)) auxPosition.y-=2;
	else if (input.IsKeyDown((int)ALLEGRO_KEY_S)) auxPosition.y+=2;

	aBox.UpdatePosition(auxPosition);
	if (aBox.CheckAABBsCollision(bBox))
	{
		printf("a-b box Collision\n");
	}
	if (aBox.CheckAABBCircleCollision(aCirc))
	{
		printf("a-a box-circ Collisions\n");
	}
	*/

	if (input.IsKeyPressed(ALLEGRO_KEY_P) && !charInput.IsActive()) m_isPaused = !m_isPaused;

	if (!m_isPaused)
	{
		if (levelManager.GetIsStarted() && !levelManager.IsGameFinished())
		{

			powerUpsManager.Update();
			/*
			if (!pU.IsActive())
			{
				pU.Spawn({ SCREEN_WIDTH / 2, -100 });
			}
			*/

			//pU.Update();

			/*
			if (pU.CheckPlayerCollision(player.GetCollider()))
			{		
				pEmitter.SetPosition(pU.GetPosition());
				pEmitter.Burst();
			}
			pEmitter.Update();
			
			*/

			powerUpsManager.CheckPlayerCollision(player.GetCollider());
			player.CheckBubblesCollision(levelManager.GetBubbles(), levelManager.GetBubblesLenght());
			player.Update();

			if (!player.IsAlive())
			{
				levelManager.RestartLevel();
				if (!levelManager.IsGameFinished()) player.SetAsAlive();
				//pEmitter.Reset();
			}
			/*
				if (levelManager.GetActiveBubblesLeft() <= 0)
				{
					levelManager.StartNextLevel();
				}
			*/
			if (!levelManager.IsGameFinished())
			{
				m_setNewHighscore = m_highscores.IsHighscore(levelManager.GetCurrentLevel(), levelManager.GetTime(), levelManager.GetAttemptsLeft());

			}
		}
		else if (levelManager.IsGameFinished())
		{
			if (m_setNewHighscore)
			{
				if (m_highscores.EnterName(levelManager.AnyTitleActive()))
				{
					m_highscores.AddNewHighscore();
					m_setNewHighscore = false;
				}
			}
		}
		levelManager.Update();

		if (powerUpsManager.IsEffectActive(EXPLOSIVE_DIARREA))
		{
			powerUpsManager.DeactivateEffect(EXPLOSIVE_DIARREA);
		}
	}
}

void Pang::Draw()
{
	levelManager.Draw();
	//pU.Draw();
	powerUpsManager.Draw();
	player.Draw();

	pEmitter.Draw();
	levelManager.DrawUI();


	if (levelManager.IsGameFinished())
	{
		if (m_setNewHighscore)
		{
			m_highscores.DrawEnterName(levelManager.AnyTitleActive());
		}
		else
		{
			m_highscores.DrawHighscores();
		}
	}
	
	if (m_isPaused)
	{
		pauseSprite.Draw({SCREEN_WIDTH/2, SCREEN_HEIGHT/2});
	}
}

void Pang::Save()
{
	m_highscores.SaveHighscores();
}
