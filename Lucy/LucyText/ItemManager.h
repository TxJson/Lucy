#ifndef ITEMMANAGER_H
#define ITEMMANAGER_H

#include "Entity.h"
#include <vector>

class ItemManager
{
public:
	ItemManager();
	~ItemManager();

	Entity GetRandomItem();
	Entity GetItem(int anItemId);
	virtual const std::vector<Entity>& GetItems() const { return myItems; }

private:
	int myItemID;
	std::vector<std::string> myFiles;
	std::vector<Entity> myItems;
	std::string myPath = "GameFiles/Items";
};

#endif