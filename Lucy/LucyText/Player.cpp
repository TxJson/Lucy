#include "Player.h"
#include "pch.h"

#define INVENTORYLIMIT myCho <= myInventory.size()-1 && myCho >= 0

Player::Player()
{
	myHealthMax = 1250;
	myHealth = myHealthMax;
	myDamage = 45;
	myLevel = 1;
	myExperience = 0;
	myGold = 275;
	myFragments = 50;
	myProtection = 1;
	myAbilities[0].myName = "Hit";
	myAbilities[0].myDamage = 15;
	myAbilities[1].myName = "Kick";
	myAbilities[1].myDamage = 20;
	myActiveFlag = true;

	EquipItem(myItemManager.GetItemByType(ItemTypes::WEAPON), ItemTypes::WEAPON, true);
	EquipItem(myItemManager.GetItemByType(ItemTypes::HELMET), ItemTypes::HELMET, true);
	EquipItem(myItemManager.GetItemByType(ItemTypes::CHESTPLATE), ItemTypes::CHESTPLATE, true);
	EquipItem(myItemManager.GetItemByType(ItemTypes::LEGGINGS), ItemTypes::LEGGINGS, true);
	EquipItem(myItemManager.GetItemByType(ItemTypes::SHOES), ItemTypes::SHOES, true);
}

Player::~Player()
{
}

void Player::Update()
{
	CalculateLevel();
	CalculateGold();
	Print
	(
		"Level: " + std::to_string(myLevel) + "\n"
		+ "Health: " + std::to_string(myHealth) + "\n"
		+ "Gold: " + std::to_string(myGold) + "\n"
		+ "Fragments: " + std::to_string(myFragments) + "\n"
		, Colour::MAGENTA
	);
}

void Player::Inventory()
{
	while (1)
	{
		Empty();
		Update();

		Print("INVENTORY: ", Colour::LIGHTCYAN);
		for (size_t i = 0; i < myInventory.size(); i++)
		{
			Print(myInventory[i].GetName());
		}
		Print("\n");
		Print("\n[1] <Inspect Item> \n[2] <Throw Away Item> \n[3] <Use/Equip Item> \n[4] <Back>");
		std::getline(std::cin, myChoToConvert);

		myCho = ConvertToInt(myChoToConvert);

		if (myInventory.size() > 0) 
		{
			if (myCho == 1 && myInventory.size() > 0)
			{
				Empty();
				Update();
				PrintInventory();

				Print("Which item would you like to inspect?", Colour::YELLOW);
				std::getline(std::cin, myChoToConvert);

				myCho = ConvertToInt(myChoToConvert);

				if (INVENTORYLIMIT)
				{
					Inspect(myInventory[myCho]);
				}
			}
			else if (myCho == 2)
			{
				Empty();
				PrintInventory();

				Print("Which item would you like to remove?");
				std::getline(std::cin, myChoToConvert);

				myCho = ConvertToInt(myChoToConvert);

				if (INVENTORYLIMIT)
				{
					myInventory[myCho].SetActiveFlag(false); //Sets the item for removal.
					Print("Removed " + myInventory[myCho].GetName() + " from your inventory.");
					Sleep(750);

					//Removes the item from the vector.
					myInventory = EraseIfDead(myInventory);
				}
			}
			else if (myCho == 3)
			{
				Empty();
				Print("Which item would you like to use/equip?\n");
				PrintInventory();

				std::getline(std::cin, myChoToConvert);

				myCho = ConvertToInt(myChoToConvert);
				if (INVENTORYLIMIT)
				{
					Empty();
					if (myInventory[myCho].GetItemType() == ItemTypes::CONSUMABLE)
					{
						Print("Used a " + myInventory[myCho].GetName() + ". \n +" + std::to_string(myInventory[myCho].GetHealingConstant()) + "HP", Colour::LIGHTGREEN);
						ModifyHealth(myInventory[myCho].GetHealingConstant());
						myInventory[myCho].SetActiveFlag(false);
					}
					else if (myInventory[myCho].GetItemType() == ItemTypes::SCROLL)
					{
						Print("That item is used for enchanting.");
					}
					else 
					{
						Print("Equipped the " + myInventory[myCho].GetName(), Colour::LIGHTGREEN);
						EquipItem(myInventory[myCho], myInventory[myCho].GetItemType(), false);
						myInventory[myCho].SetActiveFlag(false);
					}
					myInventory = EraseIfDead(myInventory);
					Sleep(1000);
				}
			}
		}
		if (myCho == 4)
		{
			break;
		}
	}
}

void Player::Gear()
{
	while (1)
	{
		Empty();
		Update();

		Print("GEAR: \n", Colour::LIGHTBLUE);
		PrintCon("Weapon: ", Colour::LIGHTCYAN);
		Print(myGear[ItemTypes::WEAPON].GetName());
		PrintCon("Helmet: ", Colour::LIGHTCYAN);
		Print(myGear[ItemTypes::HELMET].GetName());
		PrintCon("Chestplate: ", Colour::LIGHTCYAN);
		Print(myGear[ItemTypes::CHESTPLATE].GetName());
		PrintCon("Leggings: ", Colour::LIGHTCYAN);
		Print(myGear[ItemTypes::LEGGINGS].GetName());
		PrintCon("Shoes: ", Colour::LIGHTCYAN);
		Print(myGear[ItemTypes::SHOES].GetName());
		Print("\n");

		Print("[1] <Inspect> \n[2] <Unequip> \n[3] <Back>");
		std::getline(std::cin, myChoToConvert);
		myCho = ConvertToInt(myChoToConvert);

		if (myCho == 1)
		{
			Empty();
			Update();
			for (size_t i = 0; i < myGear.size(); i++)
			{
				Print("[" + std::to_string(i) + "] " + myGear[(ItemTypes)i].GetName(), Colour::LIGHTCYAN);
			}
			Print("\nWhich item would you like to inspect?", Colour::YELLOW);

			std::getline(std::cin, myChoToConvert);
			myCho = ConvertToInt(myChoToConvert);
			if (myCho >= 0 && myCho <= myGear.size())
			{
				Inspect(myGear[(ItemTypes)(myCho)]);
			}
		}
		else if (myCho == 2) 
		{
			Empty();
			Update();
			for (size_t i = 0; i < myGear.size(); i++)
			{
				Print("[" + std::to_string(i) + "] " + myGear[(ItemTypes)i].GetName(), Colour::LIGHTCYAN);
			}
			Print("\nWhich item would you like to unequip?", Colour::YELLOW);

			std::getline(std::cin, myChoToConvert);
			myCho = ConvertToInt(myChoToConvert);

			if (myCho >= 0 && myCho <= myGear.size())
			{
				UnequipItem(myGear[(ItemTypes)(myCho)], myGear[(ItemTypes)myCho].GetItemType());
			}
		}
		else if (myCho == 3) 
		{
			break;
		}
	}
}

void Player::EquipItem(Entity anItem, ItemTypes aType, bool aStartFlag = false)
{
	if (!aStartFlag)
	{
		UnequipItem(myGear[aType], aType); //Unequips current item at slot
	}

	if (aType == ItemTypes::WEAPON)
	{
		for (int i = 0; i < 2; i++)
		{
			myAbilities[i] = anItem.GetAbilities().at(i);
		}
	}
	myGear[aType] = anItem; //Equips new item

	myDamage += anItem.GetDamageMultiplier();
	myHealthMax += anItem.GetHealthMultiplier();
	myHealth += anItem.GetHealthMultiplier();
	myProtection += anItem.GetProtectionMultiplier();
}

void Player::UnequipItem(Entity anItem, ItemTypes aType)
{
	myInventory.push_back(myGear[aType]);
	if (aType == ItemTypes::WEAPON)
	{
		myAbilities[0].myName = "Hit";
		myAbilities[0].myDamage = 15;
		myAbilities[1].myName = "Kick";
		myAbilities[1].myDamage = 20;
	}
	myGear[aType] = Entity();

	myDamage -= anItem.GetDamageMultiplier();
	myHealthMax -= anItem.GetHealthMultiplier();
	myHealth -= anItem.GetHealthMultiplier();
	myProtection -= anItem.GetProtectionMultiplier();
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
		Print("[3] <Gear>");
		Print("[4] <Back>");

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
			Gear();
		}
		else if (myCho == 4)
		{
			break;
		}
	}
}

void Player::ItemHandler()
{
	Entity tempItem = myItemManager.GetRandomItem();
	while (1) 
	{
		Print("\nYou found a " + tempItem.GetName(), Colour::LIGHTGREEN);
		Print("[0] Pick up \n[1] Discard");
		
		std::getline(std::cin, myChoToConvert);

		myCho = ConvertToInt(myChoToConvert);
		if (myCho == 0 || myCho == 1)
		{
			if (myCho == 0)
			{
				Print("You picked up the " + tempItem.GetName(), Colour::LIGHTGREEN);
				GiveItem(tempItem);
			}
			else if (myCho == 1)
			{
				Print("You discarded the item.");
			}
			Print("Press 'ENTER' to continue.");
			getchar();

			break;
		}
	}
}

void Player::Enchantment()
{
	if (!InventoryContains(ItemTypes::SCROLL))
	{
		Print("You can't use this unless you have any scrolls available.");
		Print("Press 'ENTER' to return.");
		getchar();
		return;
	}
	std::vector<Entity> tempScrolls;
	for (size_t i = 0; i < myInventory.size(); i++)
	{
		if (myInventory[i].GetItemType() == ItemTypes::SCROLL) 
		{
			tempScrolls.push_back(myInventory[i]);
			myInventory[i].SetActiveFlag(false);
		}
	}
	myInventory = EraseIfDead(myInventory);
	while (1)
	{
		Print("Items: ", Colour::CYAN);
		for (size_t i = 0; i < myInventory.size(); i++)
		{
			PrintCon("[" + std::to_string(i) + "] " + myInventory[i].GetName());
			if (myInventory[i].GetEnchantable())
			{
				Print(" > Enchantable", Colour::GREEN);
			}
			else
			{
				Print(" > Not Enchantable", Colour::LIGHTRED);
			}
		}
		Print("[" + std::to_string(myInventory.size() + 1) + "] Back");

		Print("Which item would you like to enchant?");
		std::getline(std::cin, myChoToConvert);
		int tempItemCho = ConvertToInt(myChoToConvert);

		if (tempItemCho == (myInventory.size() + 1)) 
		{
			for (size_t i = 0; i < tempScrolls.size(); i++)
			{
				GiveItem(tempScrolls[i]);
			}
			break;
		}
			if (INVENTORYLIMIT)
			{
				if (myInventory[myCho].GetEnchantable())
				{
					while (1)
					{
						Print("Enchantment Available:");
						for (size_t i = 0; i < tempScrolls.size(); i++)
						{
							Print("[" + std::to_string(i) + "] " + tempScrolls[i].GetName());
						}

						Print("Choose a scroll to enchant with or to inspect.");
						std::getline(std::cin, myChoToConvert);
						myCho = ConvertToInt(myChoToConvert);

						if (myCho >= 0 && myCho <= tempScrolls.size()) 
						{
							Print("What would you like to do?", Colour::YELLOW);
							Print("[1] Enchant \n[2] Inspect");
							std::getline(std::cin, myChoToConvert);
							int tempCho = ConvertToInt(myChoToConvert);

							if (tempCho == 1) 
							{
								Print("You enchanted your " + myInventory[tempItemCho].GetName() + " with the " + tempScrolls[myCho].GetName());
								myInventory[tempItemCho].ModifyDamageMultiplier(tempScrolls[myCho].GetDamageMultiplier());
								myInventory[tempItemCho].ModifyHealthMaxMultiplier(tempScrolls[myCho].GetHealthMultiplier());
								myInventory[tempItemCho].ModifyProtectionMultiplier(tempScrolls[myCho].GetDamageMultiplier());

								Print("Press 'ENTER' to continue.");
								getchar();
								break;
							}
							else if (tempCho == 2)
							{
								Inspect(tempScrolls[myCho]);
							}
						}
					}
				}
				else
				{
					Print("That item is not enchantable.", Colour::LIGHTRED);
				}
			}
	}
}

void Player::CalculateGold()
{
	myGold = (myGold < 0) ? 0 : myGold;
}

void Player::CalculateLevel()
{
	while (myExperience >= (50 * myLevel)) 
	{
		myLevel += 1;
		myHealthMax += (100 * myLevel / 2);
		myHealth += (100 * myLevel / 2);
		myDamage += (20 * myLevel / 2);
		myProtection += (6 * myLevel / 2);
		Print("LEVEL UP!", Colour::LIGHTGREEN);
		Sleep(750);
	}
	Empty();
}

void Player::Statistics()
{
	Empty();
	Print("Statistics:", Colour::CYAN);

	PrintCon("Level: ", Colour::LIGHTCYAN);
	Print(std::to_string(GetLevel()));
	PrintCon("Health: ", Colour::LIGHTCYAN);
	Print(std::to_string(GetHealth()));
	PrintCon("Max Health: ", Colour::LIGHTCYAN);
	Print(std::to_string(GetHealthMax()));
	PrintCon("Base Damage: ", Colour::LIGHTCYAN);
	Print(std::to_string(GetDamage()));
	PrintCon("Protection: ", Colour::LIGHTCYAN);
	Print(std::to_string(GetProtection()));
	PrintCon("EXP: ", Colour::LIGHTCYAN);
	Print(std::to_string(GetExperience()) + "/" + std::to_string(50 * myLevel));

	for (int i = 0; i < 2; i++)
	{
		Print("Ability " + std::to_string(i) + ":", Colour::MAGENTA);
		PrintCon("   Name: ", Colour::MAGENTA);
		PrintCon(GetAbilities().at(i).myName);
		PrintCon(" > ", Colour::RED);
		PrintCon(std::to_string(GetAbilities().at(i).myDamage));
		Print(" Damage", Colour::RED);
	}

	Print("\nPress 'ENTER' to continue.");
	getchar();
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

bool Player::InventoryContains(ItemTypes aType)
{
	bool tempStatement = false;
	for (size_t i = 0; i < myInventory.size(); i++)
	{
		if (myInventory[i].GetItemType() == aType) 
		{
			tempStatement = true;
			break;
		}
	}
	return tempStatement;
}
