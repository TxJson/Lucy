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
	return this->myActiveFlag;
}

const int & Entity::GetHealth()
{
	return this->myHealth;
}

const int & Entity::GetHealthMax()
{
	return this->myHealthMax;
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

void Entity::SetGold(int anAmount)
{
	myGold = anAmount;
}

void Entity::SetValue(int anAmount)
{
	myValue = anAmount;
}

void Entity::ModifyGold(int someGold)
{
	myGold += someGold;
	if (myGold < 0)
	{
		myGold = 0;
	}
}

void Entity::ModifyDamageMultiplier(int anAmount)
{
	myDamageMultiplier += anAmount;
}

void Entity::ModifyHealthMaxMultiplier(int anAmount)
{
	myHealthMultiplier += anAmount;
}

void Entity::ModifyProtectionMultiplier(int anAmount)
{
	myProtectionMultiplier += anAmount;
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
	return this->myValue;
}

const bool & Entity::GetEnchantable()
{
	return myEnchantable;
}

const std::string & Entity::GetName()
{
	return this->myName;
}

const int & Entity::GetDropRate()
{
	return this->myDropRate;
}

const ItemTypes & Entity::GetItemType()
{
	return this->myItemType;
}

const int & Entity::GetExperience()
{
	return this->myExperience;
}

const std::map<int, Ability>& Entity::GetAbilities()
{
	return this->myAbilities;
}

const int & Entity::GetFragments()
{
	return this->myFragments;
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

void Entity::SetDropRate(int anAmount)
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

void Entity::SetFragments(int anAmount)
{
	myFragments = anAmount;
}

void Entity::ModifyAbilities(int aAbilityNumber, std::string aName, int anAmount)
{
	myAbilities[aAbilityNumber].myName = aName;
	myAbilities[aAbilityNumber].myDamage = anAmount;
}

void Entity::ModifyFragments(int anAmount)
{
	myFragments += anAmount;
}

void Entity::SetItemType(ItemTypes aType)
{
	myItemType = aType;
}
