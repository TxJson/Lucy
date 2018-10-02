#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"

class Player : public GameObject
{
public:
	Player(std::string aName);
	~Player();

	void Update();
};
#endif