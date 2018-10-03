#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player : public Entity
{
public:
	Player();
	~Player();

	void Update();

private:
	void CalculateGold();
};
#endif