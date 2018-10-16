#ifndef ENTITY_H
#define ENTITY_H

#include "pch.h"

struct Ability
{
	std::string Name;
	int Damage;
};

enum ItemTypes
{
	WEAPON,
	ARMOR,
	SCROLL,
	CONSUMABLE
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
	virtual const int& GetProtectionMultiplier() const { return ProtectionMultiplier; }
	virtual const int& GetDamageMultiplier() const { return DamageMultiplier; }
	virtual const int& GetHealingConstant() const { return HealingConstant; }
	virtual const int& GetHealthMultiplier() const { return HealthMultiplier; }
	virtual const int& GetCost() const { return Cost; }
	virtual const std::string& GetName() const { return Name; } //Gets Name
	virtual const float& GetDropRate() const { return DropRateChance; } //Gets Droprate
	virtual const ItemTypes& GetItemType() const { return ItemType; }

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
		ID,
		HealthMultiplier,
		DamageMultiplier,
		ProtectionMultiplier,
		HealingConstant,
		Cost;
	bool Enchantable;

	ItemTypes ItemType;
	Ability Abilities[2];
};

#endif