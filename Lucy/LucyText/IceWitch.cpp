#include "IceWitch.h"



IceWitch::IceWitch()
{
	Name = "Ice Witch";
	Health = 275;
	Damage = 19;
	DropRateChance = 0.45f;
	Abilities[0] = "Ice Ball";
	Abilities[1] = "Freeze";
}


IceWitch::~IceWitch()
{
}
