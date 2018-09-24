#include "Town.h"

Town::Town()
{
	myFirstT = true;
}

Town::~Town()
{
}

void Town::Run()
{
	while (1)
	{
		Empty();
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

			myCho = ConvertInt(myChoToConvert);
			switch (myCho)
			{
			case 1:
				Shop();
				break;
			case 2:
				OpenDimension();
				break;
			}
		}
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

void Town::OpenDimension()
{
	while (1)
	{
		Empty();
		Print("You are about to open a dimension to another realm. \nAre you sure?", 12);
		Print("[1] Yes");
		Print("[2] No");

		std::getline(std::cin, myChoToConvert);
		myCho = ConvertInt(myChoToConvert);

		if (myCho == 1)
		{
			myDimension.Run();
		}
		break;
	}
}

void Town::Shop()
{
	NotAvailable();
}