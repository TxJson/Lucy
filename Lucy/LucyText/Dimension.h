#ifndef DIMENSION_H
#define DIMENSION_H

#include "pch.h"
#include "Player.h"
#include "EnemyManager.h"

class Dimension
{
public:
	Dimension(bool aSpecialFlag);
	~Dimension();

	void Run(Player &aPlayer);
	void Generate();
	void Next(const int &aChoice);

private:
	void Battle(Player &aPlayer, bool aBossFlag);
	void FindItem(Player &aPlayer, Entity anEnemy);

	bool
		myEmptyRoom,
		mySpecialDimensionFlag;
	int
		myDoorLimit,
		myRoomSize,
		myCurrentRoom,
		myDimensionLimit,
		myDimensionLow,
		myDimensionSize,
		myEnemyAmount,
		myBossBuffAmount,
		mySpecialDungeonBonus,
		myFragmentDrop;

	EnemyManager myEnemyManager;

	int myDoorAmount[25];
	int myDoorColour[25][25];
	int myCorrectDoor[25];
	std::string myRooms[25][25];
	std::string myChoToConvert;
	std::string myDoorTypes[16] =
	{
		"Wooden",
		"Birch",
		"Beech",
		"Mahogany",
		"Maple",
		"Walnut",
		"Pine",
		"Spruce",
		"Cedar",
		"Fir",
		"Larch",
		"Oak",
		"Ash",
		"Maple",
		"Cherry",
		"Love"
	};
};

#endif