#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "pch.h"

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();

	virtual void Update();

	std::string Name;
	bool AliveFlag;
	int
		Level,
		Gold;
	float
		EncounterRate,
		DropRateChance;
	int 
		Damage,
		Health;
};

#endif