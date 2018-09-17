#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"

#define PLAYER_NAME "Lucy"
#define PLAYER_INITIAL_HEALTH 300
#define PLAYER_INITIAL_DAMAGE 25
#define PLAYER_INITIAL_LEVEL 1

class Player : public GameObject
{
public:
	Player();
	~Player();

	void Update();
};

#endif