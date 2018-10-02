#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"

class Player : public GameObject
{
public:
	Player();
	~Player();

	void Update();

private:
	void CalculateGold();
};
#endif