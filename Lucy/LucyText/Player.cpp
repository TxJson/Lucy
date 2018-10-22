#include "Player.h"
#include "pch.h"

#define INVENTORYLIMIT myCho <= myInventory.size()-1 && myCho >= 0

Player::Player()
{
	Name = "Lucy";
	myHealthMax = 1575;
	myHealth = myHealthMax;
	myDamage = 45;
	myLevel = 1;
	myGold = 150;
	myProtection = 1;
	myAbilities[0].myName = "Hit";
	myAbilities[0].myDamage = 15;
	myAbilities[1].myName = "Kick";
	myAbilities[1].myDamage = 20;
	AliveFlag = true;

	EquipItem(myItemManager.GetItemByType(ItemTypes::WEAPON), ItemTypes::WEAPON);
	EquipItem(myItemManager.GetItemByType(ItemTypes::HELMET), ItemTypes::HELMET);
	EquipItem(myItemManager.GetItemByType(ItemTypes::CHESTPLATE), ItemTypes::CHESTPLATE);
	EquipItem(myItemManager.GetItemByType(ItemTypes::LEGGINGS), ItemTypes::LEGGINGS);
	EquipItem(myItemManager.GetItemByType(ItemTypes::SHOES), ItemTypes::SHOES);
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
		+ "Level: " + std::to_string(myLevel) + "\n"
		+ "Health: " + std::to_string(myHealth) + "\n"
		+ "Gold: " + std::to_string(myGold) + "\n"
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
		Gear();
		Print("\n");
		Print("\n[1] <Inspect Item> \n[2] <Throw Away Item> \n[3] <Use/Equip Item> \n[4] <Back>");
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
						"Healing Amount: " + std::to_string(myInventory[myCho].myHealingConstant)
					);
					for (size_t i = 0; i < 2; i++)
					{
						PrintCon("Ability " + std::to_string(i + 1) + ": " + myInventory[myCho].myAbilities[i].myName);
						Print(" > " + std::to_string(myInventory[myCho].myAbilities[i].myDamage) + " Damage", Colour::LIGHTRED);
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

void Player::Gear()
{
	PrintCon("Weapon: ", Colour::LIGHTCYAN);
	Print(myGear.myWeapon.GetName());
	PrintCon("Helmet: ", Colour::LIGHTCYAN);
	Print(myGear.myHelmet.GetName());
	PrintCon("Chestplate: ", Colour::LIGHTCYAN);
	Print(myGear.myChestplate.GetName());
	PrintCon("Leggings:", Colour::LIGHTCYAN);
	Print(myGear.myLeggings.GetName());
	PrintCon("Shoes: ", Colour::LIGHTCYAN);
	Print(myGear.myShoes.GetName());
	Print("\n");
}

void Player::EquipItem(Entity anItem, ItemTypes aType)
{
	//TODO: Unequip current item first.
	switch (aType)
	{
	case ItemTypes::WEAPON:
		myGear.myWeapon = anItem;
		for (size_t i = 0; i < 2; i++)
		{
			myAbilities[i] = anItem.myAbilities[i];
		}
		break;
	case ItemTypes::HELMET:
		myGear.myHelmet = anItem;
		break;
	case ItemTypes::CHESTPLATE:
		myGear.myChestplate = anItem;
		break;
	case ItemTypes::LEGGINGS:
		myGear.myLeggings = anItem;
		break;
	case ItemTypes::SHOES:
		myGear.myShoes = anItem;
		break;
	}
	myDamage += anItem.GetDamageMultiplier();
	myHealthMax += anItem.GetHealthMultiplier();
	myHealth += anItem.GetHealthMultiplier();
	myProtection += anItem.GetProtectionMultiplier();
}

void Player::UnequipItem(ItemTypes aType)
{
}

void Player::GiveItem(Entity anItem)
{
	myInventory.push_back(anItem);
	Sleep(10);
}

void Player::Choices()
{
	while (1)
	{
		Empty();
		Update();

		Print("[1] <Statistics>");
		Print("[2] <Inventory>");
		Print("[3] <Back>");

		std::getline(std::cin, myChoToConvert);

		myCho = ConvertToInt(myChoToConvert);

		if (myCho == 1)
		{
			Statistics();
		}
		else if (myCho == 2)
		{
			Inventory();
		}
		else if (myCho == 3)
		{
			break;
		}
	}
}

void Player::CalculateGold()
{
	myGold = (myGold < 0) ? 0 : myGold;
}

void Player::Statistics()
{
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