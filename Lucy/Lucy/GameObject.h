#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();

	virtual void Update();

	int myDamage,
		myHealth;
	bool myIsAlive;
	float myEncounterRate;

	/*
	byte myCharacterID;

	string myCharacters[3] =
	{
		"Adventurer",
		"Fighter",
		"Escapist"
	};
	*/
};

#endif