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

	void Run(Player aPlayer);

private:
	void Introduction();
	void NotAvailable();
	void OpenDimension();
	void Shop();

	bool myFirstT;
	std::string myChoToConvert;
	int myCho;

	Dimension myDimension;
};

#endif