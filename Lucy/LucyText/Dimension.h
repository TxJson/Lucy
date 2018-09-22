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

private:
	int
		myDimensionLimit,
		myDimensionLow,
		myDimensionSize;

	std::string myDoors[10];
	int myDoorColour[10];

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