#include "Dimension.h"
#include "EntityManagement.h"

Dimension::Dimension()
{
	myEmptyRoom = false;
	myCurrentRoom = 0;
	myDoorLimit = 5;
	myDimensionLimit = 8;
	myDimensionLow = 3;
}

Dimension::~Dimension()
{
}

void Dimension::Run(Player &aPlayer)
{
	Generate();
	while (1)
	{
		Empty();

		if (!aPlayer.GetActiveFlag())
		{
			break;
		}

		if (myCurrentRoom >= myDimensionSize)
		{
			break;
		}

		aPlayer.Update();

		//DebugValues-start
		Print
		(
			"Dimension Size: " + std::to_string(myDimensionSize) + "\n"
			"Dimension Location: " + std::to_string(myCurrentRoom) + "\n"
			"Door Amount: " + std::to_string(myDoorAmount[myCurrentRoom]) + "\n"
			"Correct Door: " + std::to_string(myCorrectDoor[myCurrentRoom]) + "\n"
			, 14
		);
		//DebugValues-end

		if (!myEmptyRoom)
		{
			Print("Which door would you like to go through?\n", 13);
			if (myCurrentRoom > 0)
			{
				Print("[0] Back");
			}
			for (size_t i = 0; i < myDoorAmount[myCurrentRoom]; i++)
			{
				PrintCon("[" + std::to_string(i + 1), myDoorColour[myCurrentRoom][i]);
				Print("] " + myRooms[myCurrentRoom][i], myDoorColour[myCurrentRoom][i]);
			}
		}
		else
		{
			Fight(aPlayer);
			Empty();
			if (!aPlayer.GetActiveFlag())
			{
				break;
			}
			Print("This room is empty.", 13);
			Print("[0] Back");
		}

		std::getline(std::cin, myChoToConvert);

		Next(ConvertToInt(myChoToConvert));
	}
}

void Dimension::Generate()
{
	myDimensionSize = (int)Randomize(myDimensionLow, myDimensionLimit);
	for (size_t x = 0; x < myDimensionSize; x++)
	{
		myRoomSize = Randomize(myDimensionLow, myDoorLimit);
		myCorrectDoor[x] = Randomize(1, myRoomSize);
		myDoorAmount[x] = myRoomSize;
		for (size_t y = 0; y < myRoomSize; y++)
		{
			myRooms[x][y] = myDoorTypes[(int)Randomize(0, 14)] + " Door";
			myDoorColour[x][y] = (int)Randomize(1, 14);
		}
	}
	myCurrentRoom = 0;
}

void Dimension::Next(const int &aChoice)
{
	if (aChoice == myCorrectDoor[myCurrentRoom] && !myEmptyRoom)
	{
		myCurrentRoom += 1;
	}
	else if (aChoice == 0)
	{
		if (!myEmptyRoom && myCurrentRoom > 0)
		{
			myCurrentRoom -= 1;
		}
		else
		{
			myEmptyRoom = false;
		}
	}
	else if (aChoice <= myDoorAmount[myCurrentRoom] && aChoice > 0)
	{
		myEmptyRoom = true;
	}
}

void Dimension::Fight(Player &aPlayer)
{
	std::vector<Entity> tempEnemies;
	myEnemyAmount = Randomize(4, 8);
	int tempCho,
		tempLootAmount = 5,
		tempTakeDamage,
		tempDealDamage,
		tempAbilityID;

	for (size_t i = 0; i < myEnemyAmount; i++)
	{
		tempEnemies.push_back(myEnemyManager.GetEnemy());
		Sleep(10);
	}

	while (1)
	{
		tempCho = 0;
		Empty();

		if (tempEnemies.empty())
		{
			Print("All enemies are dead, you gained 50 Gold.", 10);
			aPlayer.SetGold(50);

			Print("Press 'ENTER' to continue.");
			std::getline(std::cin, myChoToConvert);
			break;
		}

		aPlayer.Update();

		Print("Enemies: ", 12);
		for (size_t i = 0; i < myEnemyAmount; i++)
		{
			PrintCon(tempEnemies[i].GetName());
			Print(" > HP: " + std::to_string(tempEnemies[i].GetHealth()), 12);
		}

		Print("\nAbilities: ", 10);
		for (int i = 0; i < 2; i++)
		{
			PrintCon("[" + std::to_string(i + 1) + "] " + aPlayer.GetAbilities().at(i).myName);
			Print(" | Damage: " + std::to_string(((aPlayer.GetDamage() + aPlayer.GetAbilities().at(i).myDamage) / (aPlayer.GetLevel()* aPlayer.GetLevel()) + aPlayer.GetDamageMultiplier())));
		}

		std::getline(std::cin, myChoToConvert);
		tempCho = ConvertToInt(myChoToConvert);
		Empty();
		for (size_t i = 0; i < tempEnemies.size(); i++)
		{
			Sleep(500);
			if (tempCho > 0 && tempCho < 3)
			{
				tempDealDamage = ((aPlayer.GetDamage() + aPlayer.GetAbilities().at(tempCho - 1).myDamage) / (aPlayer.GetLevel()* aPlayer.GetLevel())+aPlayer.GetDamageMultiplier()); //Calculated player damage.
				Print("You dealt " + std::to_string(tempDealDamage) + " damage to the " + tempEnemies[i].GetName(), Colour::LIGHTCYAN);
				tempEnemies[i].ModifyHealth(-tempDealDamage);

				Sleep(500);
				if (tempEnemies[i].GetHealth() <= 0)
				{
					Print(tempEnemies[i].GetName() + " died. Gained " + std::to_string(tempLootAmount) + " Gold", Colour::LIGHTGREEN);
					Print("Gained 25 Exp!", Colour::LIGHTGREEN);
					aPlayer.SetGold(tempLootAmount);
					aPlayer.SetExperience(25);
					FindItem(aPlayer, tempEnemies[i]);
					tempEnemies[i].SetActiveFlag(false);
					myEnemyAmount--;
				}
				else
				{
					tempAbilityID = Randomize(0, 1);
					tempTakeDamage = (((tempEnemies[i].GetDamage() + tempEnemies[i].GetAbilities().at(tempAbilityID).myDamage) / (aPlayer.GetProtection() / (aPlayer.GetLevel() * aPlayer.GetLevel()))));
					Print(tempEnemies[i].GetName() + " used " + tempEnemies[i].GetAbilities().at(tempAbilityID).myName + " and you took " + std::to_string(tempTakeDamage) + " damage.", Colour::LIGHTRED);
					aPlayer.ModifyHealth(-tempTakeDamage);
				}
			}

			if (!aPlayer.GetActiveFlag())
			{
				break;
			}
		}

		tempEnemies = EraseIfDead(tempEnemies);
		tempEnemies.resize(myEnemyAmount);

		if (aPlayer.GetHealth() <= 0)
		{
			Sleep(750);
			Print("\n\nYOU DIED!", 12);
			aPlayer.SetActiveFlag(false);
			break;
		}
	}
}

void Dimension::FindItem(Player & aPlayer, Entity anEnemy)
{
	if ((float)(Randomize(1, 100) / 100) <= anEnemy.GetDropRate())
	{
		aPlayer.ItemHandler();
	}
}
