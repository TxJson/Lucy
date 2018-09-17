#include "World.h"
#include "pch.h"
#include <ctime>

World::World()
{
	myLocation = Location::TOWN;
}

World::~World()
{
}

void World::Update()
{
	switch (myLocation)
	{
	case Location::TOWN:
		myTown.Update();
		break;
	case Location::DIMENSION:
		myDimension.Update();
		break;
	}
}