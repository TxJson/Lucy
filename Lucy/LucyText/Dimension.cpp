#include "Dimension.h"

//TODO: Crashes when out of dimensional gates

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

void Dimension::Run()
{
	Generate();
	int tempCount = 0;
	while (1)
	{
		Empty();

		if (myCurrentRoom >= myDimensionSize)
		{
			break;
		}

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
				tempCount++;
				PrintCon("[" + std::to_string(tempCount), myDoorColour[myCurrentRoom][i]);
				Print("] " + myRooms[myCurrentRoom][i], myDoorColour[myCurrentRoom][i]);
			}
			tempCount = 0;
		}
		else
		{
			Print("This room is empty.", 13);
			Print("[0] Back");
		}

		std::getline(std::cin, myChoToConvert);

		Next(ConvertInt(myChoToConvert));
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