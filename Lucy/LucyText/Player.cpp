#include "Player.h"
#include "pch.h"
#include "Calculate.h"

#define INVENTORYLIMIT myCho <= myInventory.size()-1 && myCho >= 0

Player::Player()
{
	Name = "Lucy";
	HealthMax = 1575;
	Health = HealthMax;
	Damage = 45;
	Level = 1;
	Gold = 150;
	Resistance = 1;
	Abilities[0].Name = "Hit";
	Abilities[0].Damage = 15;
	Abilities[1].Name = "Kick";
	Abilities[1].Damage = 20;
	AliveFlag = true;
}

Player::~Player()
{
}

void Player::Update()
{
	CalculateGold();
	Print
	(
		"Name: " + Name + "\n"
		+ "Level: " + std::to_string(Level) + "\n"
		+ "Health: " + std::to_string(Health) + "\n"
		+ "Gold: " + std::to_string(Gold) + "\n"
		, Colour::MAGENTA
	);
}

void Player::Inventory()
{
	while (1)
	{
		Empty();
		Update();

		Print("INVENTORY: ", 11);
		for (size_t i = 0; i < myInventory.size(); i++)
		{
			Print(myInventory[i].GetName());
		}
		Print("\n");
		Print("\n[1] <Inspect Item> \n[2] <Throw Away Item> \n[3] <Use Item> \n[4] <Back>");
		std::getline(std::cin, myChoToConvert);

		myCho = ConvertToInt(myChoToConvert);

		if (myCho == 1 && myInventory.size() > 0)
		{
			Empty();
			Update();
			Print("Which item would you like to inspect?");
			PrintInventory();
			std::getline(std::cin, myChoToConvert);

			myCho = ConvertToInt(myChoToConvert);

			if (INVENTORYLIMIT)
			{
				while (1)
				{
					Empty();
					Print
					(
						"Name: " + myInventory[myCho].GetName() + "\n" +
						"Damage: " + std::to_string(myInventory[myCho].GetDamageMultiplier()) + "\n\n" +
						"Healing Amount: " + std::to_string(myInventory[myCho].HealingConstant)
					);
					for (size_t i = 0; i < 2; i++)
					{
						PrintCon("Ability " + std::to_string(i + 1) + ": " + myInventory[myCho].Abilities[i].Name);
						Print(" > " + std::to_string(myInventory[myCho].Abilities[i].Damage) + " Damage", Colour::LIGHTRED);
					}

					Print("\n\nPress 'ENTER' to go back.");
					std::getline(std::cin, myChoToConvert);
					break;
				}
			}
		}
		else if (myCho == 2)
		{
			Empty();
			Print("Which item would you like to remove?\n");
			PrintInventory();
			std::getline(std::cin, myChoToConvert);

			myCho = ConvertToInt(myChoToConvert);

			if (INVENTORYLIMIT)
			{
				myInventory[myCho].AliveFlag = false; //Sets the item for removal.
				Print("Removed " + myInventory[myCho].GetName() + " from your inventory.");
				Sleep(750);

				//Removes the item from the vector.
				myInventory = EraseIfDead(myInventory);
			}
		}
		else if (myCho == 3)
		{
			Empty();
			Print("Which item would you like to use?\n");
			PrintInventory();

			std::getline(std::cin, myChoToConvert);

			myCho = ConvertToInt(myChoToConvert);
			if (INVENTORYLIMIT)
			{
				Empty();
				if (myInventory[myCho].GetItemType() == ItemTypes::CONSUMABLE)
				{
					Print("You used a " + myInventory[myCho].GetName() + ". \n +" + std::to_string(myInventory[myCho].GetHealingConstant()) + "HP", Colour::LIGHTGREEN);
					SetHealth(myInventory[myCho].GetHealingConstant());
					Sleep(1000);
				}
				else
				{
					Print("You can't use that item.", Colour::LIGHTRED);
					Sleep(1000);
				}
			}
		}
		else if (myCho == 4)
		{
			break;
		}
	}
}

void Player::GiveItem(Entity anItem)
{
	myInventory.push_back(anItem);
	Sleep(10);
}

void Player::CalculateGold()
{
	Gold = (Gold < 0) ? 0 : Gold;
}

void Player::PrintInventory()
{
	Print("INVENTORY: ", 11);
	for (size_t i = 0; i < myInventory.size(); i++)
	{
		Print("[" + std::to_string(i) + "] " + myInventory[i].GetName());
	}
	Print("\n");
}