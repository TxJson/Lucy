#include "Entity.h"
#include "pch.h"

Entity::Entity()
{
	AliveFlag = false;
}

Entity::~Entity()
{
}

void Entity::Update()
{
	Print("Hello");
}

void Entity::SetHealth(int someHealth)
{
	myHealth += someHealth;
	if (myHealth > myHealthMax)
	{
		myHealth = myHealthMax;
	}
	else if (myHealth < 0)
	{
		myHealth = 0;
	}
}

const int & Entity::GetHealth()
{
	return this->myHealth;
}

void Entity::SetGold(int someGold)
{
	myGold += someGold;
	if (myGold < 0)
	{
		myGold = 0;
	}
}

const int & Entity::GetGold()
{
	return this->myGold;
}

const int & Entity::GetDamage()
{
	return this->myDamage;
}

const int & Entity::GetProtection()
{
	return this->myProtection;
}

const int & Entity::GetID()
{
	return this->myId;
}

const int & Entity::GetLevel()
{
	return this->myLevel;
}

const int & Entity::GetProtectionMultiplier()
{
	return this->myProtectionMultiplier;
}

const int & Entity::GetDamageMultiplier()
{
	return this->myDamageMultiplier;
}

const int & Entity::GetHealingConstant()
{
	return this->myHealingConstant;
}

const int & Entity::GetHealthMultiplier()
{
	return this->myHealthMultiplier;
}

const int & Entity::GetCost()
{
	return this->myCost;
}

const std::string & Entity::GetName()
{
	return this->Name;
}

const float & Entity::GetDropRate()
{
	return this->myDropRate;
}

const ItemTypes & Entity::GetItemType()
{
	return this->myItemType;
}