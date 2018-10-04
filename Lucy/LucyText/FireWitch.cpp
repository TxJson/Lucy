#include "FireWitch.h"



FireWitch::FireWitch()
{
	Name = "Fire Witch";
	Health = 150;
	Damage = 10;
	DropRateChance = 0.25f;
	Abilities[0] = "Fireball";
	Abilities[1] = "Flame";
}


FireWitch::~FireWitch()
{
}
