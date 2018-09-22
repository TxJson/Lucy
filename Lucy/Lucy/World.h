#ifndef WORLD_H
#define WORLD_H

#include "Town.h"
#include "Dimension.h"

enum Location
{
	TOWN,
	DIMENSION
};

class World
{
public:
	World();
	~World();

	void Update();
	void SetLocation(const Location &aLocation) { myLocation = aLocation; }

private:
	Town myTown;
	Dimension myDimension;
	Location myLocation;
};

#endif