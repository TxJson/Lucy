#include "Entity.h"
#include "pch.h"

Entity::Entity()
{
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
	Health += someHealth;
	if (Health > HealthMax)
	{
		Health = HealthMax;
	}
	else if (Health < 0)
	{
		Health = 0;
	}
}

void Entity::SetGold(int someGold)
{
	Gold += someGold;
	if (Gold < 0)
	{
		Gold = 0;
	}
}