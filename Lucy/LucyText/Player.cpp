#include "Player.h"
#include "pch.h"

Player::Player()
{
	Name = "Lucy";
	Health = 300;
	Damage = 10;
	Level = 1;
	Gold = 150;
}

Player::~Player()
{
}

void Player::Update()
{
	CalculateGold();
	Print
	(
		"Name: " + Name + "\n"
		+ "Level: " + std::to_string(Level) + "\n"
		+ "Health: " + std::to_string(Health) + "\n"
		+ "Gold: " + std::to_string(Gold) + "\n"
		, 5
	);
}

void Player::CalculateGold()
{
	Gold = (Gold < 0) ? 0 : Gold;
}
