#include "Town.h"
#include "Game.h"

Town::Town()
{
	myTownLocation = TownPlaces::TOWNSQUARE;
}

Town::~Town()
{
}

void Town::Update()
{
	myCho = 0;
	switch (myTownLocation)
	{
	case TownPlaces::TOWNSQUARE:
		TownSquare();
		break;
	case TownPlaces::OPENDIMENSION:
		Dimension();
		break;
	case TownPlaces::SHOP:
		Shop();
		break;
	}
}

void Town::Introduction()
{
	Print(
		"Welcome to the town of " TOWNNAME "!" "\n"
		"Here you will be able to shop for gear, weapons and scrolls." "\n"
		"You could also open a breach into another dimension and fight "
		"some monsters. You know, just casual things. " "\n" "Have Fun!"

		, 3);
	Print("\nPress 'any key' to continue...");
	getchar();
	myFirstT = false;
}

void Town::NotAvailable()
{
	Print("That is currently unavailable.", 12);
	Sleep(750);
}

void Town::TownSquare()
{
	if (myFirstT)
	{
		Introduction();
	}
	else
	{
		Print("Location: " TOWNNAME ", Town Square", 11);
		Print("What would you like to do?");
		Print("[1] Shop");
		Print("[2] Open a Dimension");

		std::getline(std::cin, myChoToConvert);

		myCho = Convert(myChoToConvert);
		switch (myCho)
		{
		case 1:
			myTownLocation = TownPlaces::SHOP;
			break;
		case 2:
			myTownLocation = TownPlaces::OPENDIMENSION;
			break;
		}
	}
}

void Town::Dimension()
{
	Print("You are about to open a dimension to another realm. \nAre you sure?", 12);
	Print("[1] Yes");
	Print("[2] No");

	std::getline(std::cin, myChoToConvert);
	myCho = Convert(myChoToConvert);

	switch (myCho)
	{
	case 1:
		Game::GWorld.SetLocation(Location::DIMENSION);
		NotAvailable();
		break;
	case 2:
		myTownLocation = TownPlaces::TOWNSQUARE;
		break;
	}
}

void Town::Shop()
{
	NotAvailable();
	myTownLocation = TownPlaces::TOWNSQUARE;
}