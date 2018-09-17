#include "Player.h"

Player::Player()
{
	myName = PLAYER_NAME;
	myHealth = PLAYER_INITIAL_HEALTH;
	myDamage = PLAYER_INITIAL_DAMAGE;
	myLevel = PLAYER_INITIAL_LEVEL;
}

Player::~Player()
{
}

void Player::Update()
{
	Print
	(
		"Name: " + myName + "\n"
		+ "Level: " + std::to_string(myLevel) + "\n"
		+ "Health: " + std::to_string(myHealth) + "\n"
		, 13);
}