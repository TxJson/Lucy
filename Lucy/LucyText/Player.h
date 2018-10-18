#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include <vector>
#include "ItemManager.h"
#include "EntityManagement.h"

class Player : public Entity
{
public:
	Player();
	~Player();

	int myHealthLimit;
	void Update();
	void Inventory();
	void Gear();
	void EquipItem(Entity anItem, ItemTypes aType);
	void UnequipItem(ItemTypes aType);
	void GiveItem(Entity anItem);

private:
	ItemManager myItemManager;
	void CalculateGold();
	void PrintInventory();
	std::string myChoToConvert;
	int myCho;
	std::vector<Entity> myInventory;
	std::vector<Entity> myEquippedItems[5];
};
#endif