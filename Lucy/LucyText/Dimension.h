#ifndef DIMENSION_H
#define DIMENSION_H

#include "pch.h"

class Dimension
{
public:
	Dimension();
	~Dimension();

	void Run();
	void Generate();
	void Next(const int &aChoice);

private:
	bool myEmptyRoom;
	int
		myDoorLimit,
		myRoomSize,
		myCurrentRoom,
		myDimensionLimit,
		myDimensionLow,
		myDimensionSize;

	int myDoorAmount[25];
	int myDoorColour[25][15];
	int myCorrectDoor[25];
	std::string myRooms[25][15];
	std::string myChoToConvert;
	std::string myDoorTypes[14] =
	{
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
		"Cherry"
	};
};

#endif