#ifndef CALCULATE_H
#define CALCULATE_H

#include <algorithm>
#include <vector>
#include "Entity.h"

inline std::vector<Entity> EraseIfDead(std::vector<Entity> &someEntities)
{
	//If entity is dead, remove from vector
	someEntities.erase(
		std::remove_if(
			someEntities.begin(),
			someEntities.end(),
			[](Entity const & anEntity) { return !anEntity.AliveFlag; }
		),
		someEntities.end()
	);

	return someEntities;
}

inline void Inspect(Entity anEntity)
{
	while (1)
	{
		Empty();
		Print
		(
			"Name: " + anEntity.GetName() + "\n" +
			"Damage: " + std::to_string(anEntity.GetDamageMultiplier()) + "\n"
		);
		for (size_t i = 0; i < 2; i++)
		{
			PrintCon("Ability " + std::to_string(i + 1) + ": " + anEntity.myAbilities[i].myName);
			Print(" > " + std::to_string(anEntity.myAbilities[i].myDamage) + " Damage", Colour::LIGHTRED);
		}

		Print("\n");

		Print
		(
			"Protection Multiplier: " + std::to_string(anEntity.GetProtectionMultiplier()) + "\n" +
			"Damage Multiplier: " + std::to_string(anEntity.GetDamageMultiplier()) + "\n"
			"Health Multiplier: " + std::to_string(anEntity.GetHealthMultiplier()) + "\n"
			"Healing Constant: " + std::to_string(anEntity.GetHealingConstant())
			, Colour::GREEN
		);

		Print("Value: " + std::to_string((int)anEntity.GetCost() / 2), Colour::YELLOW);

		Print("\n\nPress 'ENTER' to go back.");
		getchar(); //Waits for ENTER
		break;
	}
}
#endif