#include "World.h"
#include "pch.h"
#include "WorldConst.h"
#include <ctime>
#include <cstdlib>

World::World()
{
	myAreaSize = GetRand();
}

World::~World()
{
}

void World::Update()
{
	Print("HELLO WORLD");
}

void World::ComputeWorld()
{
}