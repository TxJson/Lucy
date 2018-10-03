#include "Town.h"

Town::Town()
{
	myFirstT = true;
	myDimensionCost = 50;
}

Town::~Town()
{
}

void Town::Run(const Player aPlayer)
{
	myPlayer = aPlayer;
	while (1)
	{
		Empty();
		if (myFirstT)
		{
			Introduction();
		}
		else
		{
			myPlayer.Update();

			Print("Location: " TOWNNAME ", Town Square", 11);
			Print("What would you like to do?");
			Print("[1] <Shop>\n[2] <Crafting Station>\n[3] <Open a Dimension>");

			std::getline(std::cin, myChoToConvert);

			myCho = ConvertInt(myChoToConvert);
			switch (myCho)
			{
			case 1:
				Shop();
				break;
			case 2:
				NotAvailable();
				break;
			case 3:
				OpenDimension();
				break;
			case 481:
				myPlayer.Gold = 15000; //Cheat code for easier debugging.
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
	Sleep(1000);
}

void Town::OpenDimension()
{
	while (1)
	{
		Empty();
		myPlayer.Update();
		Print("Opening a dimension costs " +
			std::to_string(myDimensionCost) +
			" Gold. \nAre you sure you want to proceed?", 12);
		Print("[1] Yes\n[2] No");

		std::getline(std::cin, myChoToConvert);
		myCho = ConvertInt(myChoToConvert);

		if (myCho == 1)
		{
			if (myPlayer.Gold >= myDimensionCost)
			{
				myPlayer.Gold -= myDimensionCost;
				myDimension.Run(myPlayer);
			}
			else
			{
				NotEnoughMoney();
			}
			break;
		}
		else if (myCho == 2)
		{
			break;
		}
	}
}

void Town::Shop()
{
	NotAvailable();
}

void Town::NotEnoughMoney()
{
	Print("Not enough money.", 12);
	Sleep(1000);
}