#pragma once

#include "pch.h"
#include "GameStates.h"
#include <stdlib.h>

using namespace std;

class Game
{
public:
	Game();
	~Game();

	void Run();
	void Update();
	static void ClearScreen();

	//Accessors
	inline bool GetIsRunning() const { return this->myIsRunning; }

private:
	bool myIsRunning; //'TRUE' if game is running.
public:
	int myCho; //My Choice
	GameState myGState;
};

