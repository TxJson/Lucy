#include "Town.h"
#include "ItemManager.h"

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
			Print("[1] <Shop>\n[2] <Enchantment Station>\n[3] <Open a Dimension> \n[4] <Inventory> ");
			std::getline(std::cin, myChoToConvert);

			myCho = ConvertToInt(myChoToConvert);
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
			case 4:
				myPlayer.Inventory();
				break;
			case 47190:
				myPlayer.SetGold(15000); //Cheat code for easier debugging.
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
		myCho = ConvertToInt(myChoToConvert);

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
	myItems = myItemManager.GetItems();
	while (1) 
	{
		Empty();
		myPlayer.Update();
		Print("SHOP:", 11);
		for (size_t i = 0; i < myItems.size(); i++)
		{
			PrintCon("[" + std::to_string(i) + "] " + myItems[i].GetName());
			Print(" > " + std::to_string(myItems[i].GetCost()) + " Gold", 14);
		}
		Print("\n");

		Print("\n[1] <Buy an Item> | [2] <Inspect Item> | [3] <Inventory> | [4] <Back>");
		std::getline(std::cin, myChoToConvert);

		myCho = ConvertToInt(myChoToConvert);

		if (myCho == 1) 
		{
			myCho = -1;
			while (1) 
			{
				Empty();
				myPlayer.Update();
				Print("SHOP:", 11);
				for (size_t i = 0; i < myItems.size(); i++)
				{
					PrintCon("[" + std::to_string(i) + "] " + myItems[i].GetName());
					Print(" > " + std::to_string(myItems[i].GetCost()) + " Gold", 14);
				}
				Print("\n[" + std::to_string(myItems.size() + 1) + "] Back");
				Print("Which item would you like to buy?");
				std::getline(std::cin, myChoToConvert);

				myCho = ConvertToInt(myChoToConvert);
				if (myCho >= 0 && myCho <= myItems.size())
				{
					if (myPlayer.GetGold() >= myItems[myCho].GetCost())
					{
						myPlayer.SetGold(-myItems[myCho].GetCost());
						Print("You successfully bought a " + myItems[myCho].GetName());
						myPlayer.GiveItem(myItems[myCho]);
						Sleep(1000);
					}
					else
					{
						NotEnoughMoney();
					}
				}
				else if (myCho == (myItems.size() + 1))
				{
					break;
				}
			}
		}
		else if (myCho == 2)
		{
			Empty();
			Print("SHOP:", 11);
			for (size_t i = 0; i < myItems.size(); i++)
			{
				Print("[" + std::to_string(i) + "] " + myItems[i].GetName());
			}
			Print("\n");
			Print("Which item would you like to inspect?");
			std::getline(std::cin, myChoToConvert);

			myCho = ConvertToInt(myChoToConvert);
			while (1)
			{
				Empty();
				Print
				(
					"Name: " + myItems[myCho].GetName() + "\n" +
					"Damage: " + std::to_string(myItems[myCho].GetDamageMultiplier()) + "\n\n" + 
					"Healing Amount: " + std::to_string(myItems[myCho].HealingConstant)

				);
				for (size_t i = 0; i < 2; i++)
				{
					PrintCon("Ability " + std::to_string(i + 1) + ": " + myItems[myCho].Abilities[i].Name);
					Print(" > " + std::to_string(myItems[myCho].Abilities[i].Damage) + " Damage", 12);
				}
				Print("Cost: " + std::to_string(myItems[myCho].GetCost()), 14);

				Print("\n\nPress 'ENTER' to go back.");
				std::getline(std::cin, myChoToConvert);
				break;
			}
		}
		else if (myCho == 3) 
		{
			myPlayer.Inventory();
		}
		else if (myCho == 4)
		{
			break;
		}
	}
	myItems.clear();
}

void Town::NotEnoughMoney()
{
	Print("Not enough money.", 12);
	Sleep(1000);
}