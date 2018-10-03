#ifndef ENTITY_H
#define ENTITY_H

#include "pch.h"

class Entity
{
public:
	Entity();
	virtual ~Entity();

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