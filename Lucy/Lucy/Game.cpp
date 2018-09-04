#include "Game.h"
#include "pch.h"
#include <stdlib.h>
#include "Player.h"

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

		Empty();
		//Print("Hello There, General Kenobi");
		break;

	case GameState::GAME:
		myPlayer.Update();
		break;
	}
}