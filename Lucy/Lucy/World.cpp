#include "World.h"
#include "pch.h"
#include <ctime>

World::World()
{
	//myAreaSize = WORLD_MIN_AREA+(rand()%WORLD_MAX_AREA);
	myAreaSize = 0;
	myLocation = Location::TOWN;
	myFirstT = true;
}

World::~World()
{
}

void World::Update()
{
	switch (myLocation)
	{
	case Location::TOWN:
		Town();
		break;
	case Location::DIMENSION:

		break;
	}
	//Print("" + myAreaSize);
	//myAreaSize = WORLD_MIN_AREA + (rand() % WORLD_MAX_AREA); //Remove later
}

void World::Town()
{
	if (myFirstT)
	{
		Introduction();
	}
	else
	{
		SetColour(11);
		Print("TOWN: " TOWNNAME);
		ResetColour();

		Print("What would you like to do?");
		Print("[1] Shop");
		Print("[2] Open a Dimension");

		std::string tempCho;
		std::getline(std::cin, tempCho);

		if (tempCho != "")
		{
			try
			{
				myCho = std::stoi(tempCho);
			}
			catch (...) {}
			switch (myCho)
			{
			case 1:
				NotAvailable();
				break;
			case 2:
				NotAvailable();
				break;
			}
		}
	}
}

void World::Introduction()
{
	SetColour(3);
	Print(
		"Welcome to the town of " TOWNNAME "!" "\n"
		"Here you will be able to shop for gear, weapons and scrolls." "\n"
		"You could also open a breach into another dimension and fight "
		"some monsters. You know, just casual things. " "\n" "Have Fun!"

	);

	ResetColour();
	Print("\nPress 'any key' to continue...");
	getchar();
	myFirstT = false;
}

void World::NotAvailable()
{
	SetColour(12);
	Print("That is currently unavailable.");
	Sleep(750);
	ResetColour();
}