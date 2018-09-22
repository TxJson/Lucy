#include "World.h"
#include "pch.h"
#include "WorldConst.h"
#include <ctime>

World::World()
{
	myAreaSize = WORLD_MIN_AREA+(rand()%WORLD_MAX_AREA);
}

World::~World()
{
}

void World::Update()
{
	Print("" + myAreaSize);
	myAreaSize = WORLD_MIN_AREA + (rand() % WORLD_MAX_AREA);
}

void World::ComputeWorld()
{
}