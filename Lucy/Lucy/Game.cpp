#include "Game.h"
#include "pch.h"
#include <stdlib.h>
#include "Player.h"
#include "Menu.h";

Game::Game()
{
	myGState = GameState::MENU;
	myIsRunning = true;
}

Game::~Game()
{
}

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
		myMenu.Update();
		break;

	case GameState::GAME:
		myPlayer.Update();
		break;
	}
}