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

#endif