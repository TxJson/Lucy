#include "Menu.h"
#include "pch.h"
#include "Game.h"

Menu::Menu()
{
	myCho = 0;
	myMStates = MenuStates::MENU;
}

Menu::~Menu()
{
}

void Menu::Update()
{
	switch (myMStates)
	{
	case MenuStates::MENU:
		MenuDisplay();
		break;
	case MenuStates::START:
		StartDisplay();
		break;
	}
	Input();
}

void Menu::MenuDisplay()
{
	Empty();
	Print("LUCY");
	Print("[1] Start");
	Print("[2] Exit");
}

void Menu::StartDisplay()
{
}

void Menu::Input()
{
	std::cin >> myCho;

	if (myMStates == MenuStates::MENU)
	{
		switch (myCho)
		{
		case 1:
			myMStates = MenuStates::START;
			break;
		case 2:
			break;
		}
	}
	else if (myMStates == MenuStates::START)
	{
		switch (myCho)
		{
		case 1:
			myMStates = MenuStates::NEWGAME;
			break;
		}
	}
}