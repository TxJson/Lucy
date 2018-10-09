#include "Player.h"
#include "pch.h"

Player::Player()
{
	Name = "Lucy";
	HealthMax = 450;
	Health = HealthMax;
	Damage = 10;
	Level = 1;
	Gold = 150;
	Resistance = 1;
	Abilities[0].Name = "Hit";
	Abilities[0].Damage = 15;
	Abilities[1].Name = "Kick";
	Abilities[1].Damage = 20;
	AliveFlag = true;
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