#ifndef ENTITY_H
#define ENTITY_H

#include "pch.h"

struct Ability
{
	std::string Name;
	int Damage;
};

class Entity
{
public:
	Entity();
	virtual ~Entity();

	virtual void Update();
	virtual void SetHealth(int someHealth); //Sets Health
	virtual const int& GetHealth() const { return Health; } //Gets Health
	virtual void SetGold(int someGold); //Sets Gold
	virtual const int& GetGold() const { return Gold; } //Gets Gold
	virtual const int& GetDamage() const { return Damage; }
	virtual const int& GetResistance() const { return Resistance; } //Gets Resistance
	virtual const int& GetID() const { return ID; } //Gets ID
	virtual const int& GetLevel() const { return Level; }
	virtual const std::string& GetName() const { return Name; } //Gets Name
	virtual const float& GetDropRate() const { return DropRateChance; } //Gets Droprate

	std::string Name;
	bool AliveFlag;
	int
		Level,
		Gold,
		Resistance;
	float
		DropRateChance;
	int
		Health,
		HealthMax,
		Damage,
		ID;

	Ability Abilities[2];
};

#endif