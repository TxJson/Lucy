#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "pch.h"

#define PLAYER_NAME "Lucy"
#define PLAYER_INITIAL_HEALTH 300.0f
#define PLAYER_INITIAL_DAMAGE 25.0f
#define PLAYER_INITIAL_LEVEL 1

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();

	virtual void Update();

	std::string myName;
	bool myIsAlive;
	int
		myLevel;
	float
		myEncounterRate,
		myDropRateChance;
	int myDamage,
		myHealth;
};

#endif