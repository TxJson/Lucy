#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "pch.h"

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