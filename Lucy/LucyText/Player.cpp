#include "Player.h"
#include "pch.h"

Player::Player(std::string aName)
{
	myName = aName;
	myHealth = 300;
	myDamage = 10;
	myLevel = 1;
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
		, 13
	);
}