#include "Game.h"
#include "pch.h"
#include <stdlib.h>
#include "GameConst.h"

Game::Game()
{
	myGState = GameState::MENU;
	myExecutionFlag = true;
}

Game::~Game()
{
}

void Game::Run()
{
	while (myExecutionFlag)
	{
		Update();
	}
}

void Game::Update()
{
	switch (myGState)
	{
	case GameState::MENU:
		MainMenu();
		break;

	case GameState::GAME:
		myPlayer.Update();
		myWorld.Update();
		break;
	}
	Sleep(25);
	Empty();
}

void Game::MainMenu()
{
	Print("GAME: " NAME, 12);
	Print("Author: " AUTHOR "\n", 12);
	Print("[1] Start");
	Print("[2] Exit \n");

	std::string tempCho;
	std::getline(std::cin, tempCho);

	if (tempCho != "")
	{
		try
		{
			myCho = std::stoi(tempCho);
		}
		catch (...) {}
		switch (myCho)
		{
		case 1:
			myGState = GameState::GAME;
			break;
		case 2:
			myExecutionFlag = false;
			break;
		}
	}
}