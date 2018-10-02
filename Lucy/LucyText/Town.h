#ifndef TOWN_H
#define TOWN_H

#include "pch.h"
#include "Dimension.h"
#include "Player.h"

#define TOWNNAME "Rackford"
class Town
{
public:
	Town();
	~Town();

	void Run(const Player aPlayer);

private:
	void Introduction();
	void NotAvailable();
	void OpenDimension();
	void Shop();
	void NotEnoughMoney();

	bool myFirstT;
	std::string myChoToConvert;
	int
		myCho,
		myDimensionCost;
	Player myPlayer;

	Dimension myDimension;
};

#endif