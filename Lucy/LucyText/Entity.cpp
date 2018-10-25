#include "Entity.h"
#include "pch.h"

Entity::Entity()
{
	myActiveFlag = false;
}

Entity::~Entity()
{
}

void Entity::Update()
{
	Print("Hello");
}

void Entity::ModifyHealth(int someHealth)
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

const bool & Entity::GetActiveFlag()
{
	return myActiveFlag;
}

const int & Entity::GetHealth()
{
	return this->myHealth;
}

const int & Entity::GetHealthMax()
{
	return myHealthMax;
}

void Entity::SetDamageMultiplier(int anAmount)
{
	myDamageMultiplier = anAmount;
}

void Entity::SetProtectionMultiplier(int anAmount)
{

	myProtectionMultiplier = anAmount;
}

void Entity::SetHealthMultiplier(int anAmount)
{
	myHealthMultiplier = anAmount;
}

void Entity::SetEnchantable(bool aStatement)
{
	myEnchantable = aStatement;
}

void Entity::SetHealingConstant(int anAmount)
{
	myHealingConstant = anAmount;
}

void Entity::SetCost(int anAmount)
{
	myCost = anAmount;
}

void Entity::SetValue(int anAmount)
{
	myValue = anAmount;
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

const int & Entity::GetValue()
{
	return myValue;
}

const std::string & Entity::GetName()
{
	return this->myName;
}

const float & Entity::GetDropRate()
{
	return this->myDropRate;
}

const ItemTypes & Entity::GetItemType()
{
	return this->myItemType;
}

const int & Entity::GetExperience()
{
	return myExperience;
}

const std::map<int, Ability>& Entity::GetAbilities()
{
	return myAbilities;
}

void Entity::SetExperience(int anAmount)
{
	myExperience += anAmount;
}

void Entity::SetName(std::string aName)
{
	myName = aName;
}

void Entity::SetId(int anId)
{
	myId = anId;
}

void Entity::SetHealthMax(int anAmount)
{
	myHealthMax = anAmount;
}

void Entity::SetHealth(int anAmount)
{
	myHealth = anAmount;
}

void Entity::SetDamage(int anAmount)
{
	myDamage = anAmount;
}

void Entity::SetDropRate(float anAmount)
{
	myDropRate = anAmount;
}

void Entity::SetActiveFlag(bool aStatement)
{
	myActiveFlag = aStatement;
}

void Entity::SetAbilities(std::map<int, Ability> someAbilities)
{
	myAbilities = someAbilities;
}

void Entity::ModifyAbilities(int aAbilityNumber, std::string aName, int anAmount)
{
	myAbilities[aAbilityNumber].myName = aName;
	myAbilities[aAbilityNumber].myDamage = anAmount;
}

void Entity::SetItemType(ItemTypes aType)
{
	myItemType = aType;
}
