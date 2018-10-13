#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include <vector>

class Player : public Entity
{
public:
	Player();
	~Player();

	int myHealthLimit;
	void Update();
	void Inventory();
	void GiveItem(Entity anItem);

private:
	void CalculateGold();
	void PrintInventory();
	std::string myChoToConvert;
	int myCho;
	std::vector<Entity> myInventory;
};
#endif