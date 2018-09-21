#ifndef TOWN_H
#define TOWN_H

#include "pch.h"

#define TOWNNAME "Rackford"

enum TownPlaces
{
	TOWNSQUARE,
	OPENDIMENSION,
	SHOP
};

class Town
{
public:
	Town();
	~Town();

	void Update();

	TownPlaces myTownLocation;

private:
	void Introduction();
	void NotAvailable();
	void Dimension();
	void TownSquare();
	void Shop();

	bool myFirstT;
	std::string myChoToConvert;
	int myCho;
};

#endif