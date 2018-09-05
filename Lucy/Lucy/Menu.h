#pragma once
#include "Game.h"

class Menu
{
	enum MenuStates
	{
		MENU,
		START,
		NEWGAME,
		LOADGAME,
	};

public:
	Menu();
	~Menu();

	void Update();

private:
	void MenuDisplay();
	void StartDisplay();
	void Input();

	int myCho; //Choice
	MenuStates myMStates;
};
