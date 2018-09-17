#include "Town.h"
#include "pch.h"

Town::Town()
{
}

Town::~Town()
{
}

void Town::Update()
{
	if (myFirstT)
	{
		Introduction();
	}
	else
	{
		Print("Location: " TOWNNAME, 11);

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
		myCho = 0;
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