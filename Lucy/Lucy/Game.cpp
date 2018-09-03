#include "Game.h"

Game::Game()
{
	myCho = 0;
	myGState = GameState::MENU;
	myIsRunning = true;
}

Game::~Game()
{}

void Game::Run()
{
	while (myIsRunning)
	{
		Update();
	}
}

void Game::Update()
{
	switch (myGState)
	{
	case GameState::MENU:
		ClearScreen();
		cout << "Hello There" << endl; //Test
		break;

	case GameState::GAME:

		break;
	}
}

void Game::ClearScreen()
{
	system("CLS");
}