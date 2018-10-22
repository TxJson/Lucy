#ifndef ENTITY_H
#define ENTITY_H

#include "pch.h"

struct Ability
{
	std::string myName;
	int myDamage;
};

enum ItemTypes
{
	WEAPON,
	HELMET,
	CHESTPLATE,
	LEGGINGS,
	SHOES,
	SCROLL,
	CONSUMABLE,
	LENGTH
};

class Entity
{
public:
	Entity();
	virtual ~Entity();

	virtual void Update();
	virtual void SetHealth(int someHealth); //Sets Health
	virtual const int& GetHealth(); //Gets Health
	virtual void SetGold(int someGold); //Sets Gold
	virtual const int& GetGold(); //Gets Gold
	virtual const int& GetDamage();
	virtual const int& GetProtection(); //Gets Resistance
	virtual const int& GetID(); //Gets ID
	virtual const int& GetLevel();
	virtual const int& GetProtectionMultiplier();
	virtual const int& GetDamageMultiplier();
	virtual const int& GetHealingConstant();
	virtual const int& GetHealthMultiplier();
	virtual const int& GetCost();
	virtual const std::string& GetName();
	virtual const float& GetDropRate();
	virtual const ItemTypes& GetItemType();

	std::string Name;
	bool AliveFlag;
	int
		myLevel,
		myGold,
		myProtection;
	float
		myDropRate;
	int
		myHealth,
		myHealthMax,
		myDamage,
		myId,
		myHealthMultiplier,
		myDamageMultiplier,
		myProtectionMultiplier,
		myHealingConstant,
		myCost;
	bool myEnchantable;

	ItemTypes myItemType;
	Ability myAbilities[2];
};

#endif