#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "pch.h"

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();

	virtual void Update();

protected:
	string myName;
	bool myIsAlive;
	int myLevel;
	float
		myEncounterRate,
		myDropRateChance,
		myDamage,
		myHealth;
};

#endif