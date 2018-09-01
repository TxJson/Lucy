#pragma once

class GameObject
{
public:
	GameObject();
	~GameObject();

	virtual void Update();

public:
	int myDamage,
		myHealth;
	bool myIsAlive;

};

