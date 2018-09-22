#pragma once
class GameObject
{
public:
	GameObject();
	virtual ~GameObject();

	virtual void Update();

	std::string myName;
	bool myIsAlive;
	int
		myLevel;
	float
		myEncounterRate,
		myDropRateChance;
	int myDamage,
		myHealth;
};

