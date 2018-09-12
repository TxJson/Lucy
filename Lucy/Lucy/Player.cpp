#include "Player.h"
#include "pch.h"
#include "PlayerInfoConst.h"

Player::Player()
{
	myName = PLAYER_NAME;
	myHealth = PLAYER_INITIAL_HEALTH;
	myDamage = PLAYER_INITIAL_DAMAGE;
}

Player::~Player()
{
}

void Player::Update()
{
	Print(myName);
}