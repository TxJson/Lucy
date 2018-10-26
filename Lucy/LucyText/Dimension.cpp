#include "Dimension.h"
#include "EntityManagement.h"

Dimension::Dimension(bool aSpecialFlag)
{
	mySpecialDimensionFlag = aSpecialFlag;
	myEmptyRoom = false;
	myCurrentRoom = 0;
	myDoorLimit = (aSpecialFlag) ? 15 : 5;
	myDimensionLimit = (aSpecialFlag) ? 16: 8;
	myDimensionLow = (aSpecialFlag) ? 8: 3;
	myBossBuffAmount = (aSpecialFlag) ? 20 : 10; //In the case of a boss, increases boss stats by this amount
	mySpecialDungeonBonus = 10;
	myFragmentDrop = Randomize(1, 25);
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
			Battle(aPlayer, true);
			Print("You've made it out alive!", Colour::LIGHTGREEN);
			Print("+" + std::to_string(myFragmentDrop) + " Fragments!", Colour::LIGHTGREEN);
			aPlayer.ModifyFragments(myFragmentDrop);
			Print("\nPress 'ENTER' to continue.");
			getchar();
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
			Print("\n[" + std::to_string(myDoorAmount[myCurrentRoom]+1) + "] Player Information", Colour::WHITE);
		}
		else
		{
			Battle(aPlayer, false);
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
		if (ConvertToInt(myChoToConvert) == myDoorAmount[myCurrentRoom]+1)
		{
			aPlayer.Choices();
		}
	}
}

void Dimension::Generate()
{
	myDimensionSize = (int)Randomize(myDimensionLow, myDimensionLimit);
	for (size_t x = 0; x < myDimensionSize; x++)
	{
		myRoomSize = Randomize(myDimensionLow, myDoorLimit); //Sets the size of the room
		myCorrectDoor[x] = Randomize(1, myRoomSize); //Sets the correct door to continue into the dimension
		myDoorAmount[x] = myRoomSize; //Determine door amount per room
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

void Dimension::Battle(Player &aPlayer, bool aBossFlag)
{
	std::vector<Entity> tempEnemies;
	myEnemyAmount = (aBossFlag) ? 1 : Randomize(4, 8);
	int tempCho,
		tempTakeDamage,
		tempDealDamage,
		tempAbilityID;

	int tempEnemyExpDrop = (mySpecialDimensionFlag) ? 25 * mySpecialDungeonBonus : 25;
	int tempBattleFinishDrop = (mySpecialDimensionFlag) ? 50 * mySpecialDungeonBonus : 50;
	int tempLootAmount = (mySpecialDimensionFlag) ? 50 : 5;

	for (size_t i = 0; i < myEnemyAmount; i++)
	{
		tempEnemies.push_back(myEnemyManager.GetEnemy());

		if (aBossFlag) 
		{
			tempEnemies[i].SetHealthMax(tempEnemies[i].GetHealthMax() * 2);
			tempEnemies[i].SetHealth(tempEnemies[i].GetHealthMax());
		}
		Sleep(10);
	}


	while (1)
	{
		tempCho = 0;
		Empty();
		aPlayer.Update();

		if (tempEnemies.empty())
		{
			Print("All enemies are dead, you gained " + std::to_string(tempBattleFinishDrop) + " Gold.", 10);
			aPlayer.ModifyGold(tempBattleFinishDrop);

			Print("Press 'ENTER' to continue.");
			getchar();
			break;
		}
		Print((aBossFlag) ? "BOSS BATTLE: " : "BATTLE: ", Colour::LIGHTCYAN); //Changes text depending on the aBossFlag variable

		for (size_t i = 0; i < myEnemyAmount; i++)
		{
			PrintCon((aBossFlag) ? "The Almighty " + tempEnemies[i].GetName() : tempEnemies[i].GetName());
			Print(" > HP: " + std::to_string(tempEnemies[i].GetHealth()), Colour::LIGHTRED);
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
			if (tempCho > 0 && tempCho < (aPlayer.GetAbilities().size()+1))
			{
				tempDealDamage = ((aPlayer.GetDamage() + aPlayer.GetAbilities().at(tempCho - 1).myDamage) / (aPlayer.GetLevel()* aPlayer.GetLevel())+aPlayer.GetDamageMultiplier()); //Calculated player damage.
				Print("Dealt " + std::to_string(tempDealDamage) + " damage to the " + tempEnemies[i].GetName(), Colour::LIGHTCYAN);
				tempEnemies[i].ModifyHealth(-tempDealDamage);

				Sleep(500);
				if (tempEnemies[i].GetHealth() <= 0)
				{
					PrintCon(tempEnemies[i].GetName() + " died.", Colour::LIGHTGREEN);
					PrintCon(" | +" + std::to_string(tempLootAmount) + " Gold!", Colour::YELLOW);
					Print(" | +" + std::to_string(tempEnemyExpDrop) + " Exp!", Colour::LIGHTGREEN);
					aPlayer.ModifyGold(tempLootAmount);
					aPlayer.SetExperience(tempEnemyExpDrop);
					FindItem(aPlayer, tempEnemies[i]);
					tempEnemies[i].SetActiveFlag(false);
					myEnemyAmount--;
				}
				else
				{
					tempAbilityID = Randomize(0, 1);
					tempTakeDamage = (((tempEnemies[i].GetDamage() + tempEnemies[i].GetAbilities().at(tempAbilityID).myDamage) / (aPlayer.GetProtection() / (aPlayer.GetLevel() * aPlayer.GetLevel()))));
					tempTakeDamage *= (aBossFlag) ? myBossBuffAmount : 1; //Increases the damage if enemy is a boss
					PrintCon(tempEnemies[i].GetName() + " used " + tempEnemies[i].GetAbilities().at(tempAbilityID).myName, Colour::LIGHTRED);
					Print(" | -" + std::to_string(tempTakeDamage) + " Health", Colour::RED);
					aPlayer.ModifyHealth(-tempTakeDamage);
				}
				Sleep(500);
			}

			if (!aPlayer.GetActiveFlag())
			{
				break;
			}
		}

		tempEnemies = EraseIfDead(tempEnemies);

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
	if ((Randomize(1, 100)) <= anEnemy.GetDropRate())
	{
		aPlayer.ItemHandler();
	}
}
