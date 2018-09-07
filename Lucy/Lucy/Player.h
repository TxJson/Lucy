#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
using namespace std;

class Player : public GameObject
{
public:
	Player();
	~Player();

	void Update();
};

#endif
