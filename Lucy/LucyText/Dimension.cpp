#include "Dimension.h"

Dimension::Dimension()
{
	myDimensionLimit = 10;
	myDimensionLow = 3;
}


Dimension::~Dimension()
{
}

void Dimension::Run()
{
	Generate();
	while (1) 
	{
		for (size_t i = 0; i < myDimensionSize; i++)
		{
			Print(myDoors[i], myDoorColour[i]);
		}
	}
}

void Dimension::Generate()
{
	myDimensionSize = Randomize(myDimensionLow, myDimensionLimit);
	for (size_t i = 0; i < myDimensionSize; i++)
	{
		myDoors[i] = myDoorTypes[Randomize(myDimensionLow, myDimensionLimit)] + " Door";
		myDoorColour[i] = Randomize(1, 16);
		Sleep(25);
	}
}