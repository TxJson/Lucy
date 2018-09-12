#include "Player.h"
#include "PlayerConst.h"

Player::Player()
{
	myName = PLAYER_NAME;
	myHealth = PLAYER_INITIAL_HEALTH;
	myDamage = PLAYER_INITIAL_DAMAGE;
	myLevel = PLAYER_INITIAL_LEVEL;
	myHunger = PLAYER_INITIAL_HUNGER;
	myWater = PLAYER_INITIAL_WATER;
}

Player::~Player()
{
}

void Player::Update()
{
	Print
	(
		"Name: " + myName + "\n"
		+ "Lvl: " + std::to_string(myLevel) + "\n"
		+ "Health: " + std::to_string(myHealth) + "\n"
		+ "Thirst: " + std::to_string(myWater) + "\n"
		+ "Hunger: " + std::to_string(myHunger)
	);
}