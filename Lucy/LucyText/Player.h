#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include <vector>
#include "ItemManager.h"
#include "EntityManagement.h"

struct GearToEquip
{
	Entity myHelmet;
	Entity myChestplate;
	Entity myLeggings;
	Entity myShoes;
	Entity myWeapon;
};

class Player : public Entity
{
public:
	Player();
	~Player();

	int myHealthLimit;
	void Update();
	void Gear();
	void EquipItem(Entity anItem, ItemTypes aType);
	void UnequipItem(ItemTypes aType);
	void GiveItem(Entity anItem);
	void Choices();

private:
	ItemManager myItemManager;
	void CalculateGold();
	void Statistics();
	void Inventory();
	void PrintInventory();
	std::string myChoToConvert;
	int myCho;
	GearToEquip myGear;
	std::vector<Entity> myInventory;
};
#endif