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

	int myDoorAmount[150];
	int myDoorColour[150][150];
	int myCorrectDoor[150];
	std::string myRooms[150][150];
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