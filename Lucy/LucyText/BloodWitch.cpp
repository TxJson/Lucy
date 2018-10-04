#include "BloodWitch.h"



BloodWitch::BloodWitch()
{
	Name = "Blood Witch";
	Health = 175;
	Damage = 25;
	DropRateChance = 0.45f;
	Abilities[0] = "Drain";
	Abilities[1] = "Drown";
}


BloodWitch::~BloodWitch()
{
}
