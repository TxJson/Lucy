#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include <vector>
#include "ItemManager.h"
#include "EntityManagement.h"
#include <map>

class Player : public Entity
{
public:
	Player();
	~Player();

	int myHealthLimit;
	void Update();
	void Gear();
	void EquipItem(Entity anItem, ItemTypes aType, bool aStartFlag);
	void UnequipItem(Entity anItem, ItemTypes aType);
	void GiveItem(Entity anItem);
	void Choices();
	void ItemHandler();
	void Enchantment();

private:
	void CalculateGold();
	void CalculateLevel();
	void Statistics();
	void Inventory();
	void PrintInventory();
	bool InventoryContains(ItemTypes aType);

	int myCho;
	ItemManager myItemManager;
	std::string myChoToConvert;
	std::vector<Entity> myInventory;
	std::map<ItemTypes, Entity> myGear;
};
#endif