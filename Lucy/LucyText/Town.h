#ifndef TOWN_H
#define TOWN_H

#include "pch.h"
#include "Dimension.h"
#include "Player.h"
#include "ItemManager.h"
#include "Entity.h"

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
	bool CheckCertain();

	bool myFirstT;
	std::string myChoToConvert;
	int
		myCho,
		mySpecialDimensionCost;
	Player myPlayer;
	ItemManager myItemManager;
	std::vector<Entity> myItems;
};

#endif