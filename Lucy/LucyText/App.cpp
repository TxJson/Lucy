#include "App.h"
#include "pch.h"

App::App()
{
}

App::~App()
{
}

void App::Menu()
{
	while (1)
	{
		Empty();
		Print("GAME: " NAME, Colour::LIGHTRED);
		Print("Author: " AUTHOR "\n", Colour::LIGHTRED);
		Print("[1] <Start>\n[2] <Exit>\n");

		std::string tempCho;
		std::getline(std::cin, tempCho);

		if (tempCho != "")
		{
			myCho = ConvertToInt(tempCho);

			if (myCho == 1)
			{
				Player *tempPlayer = new Player();
				myTown.Run(*tempPlayer);
				delete(tempPlayer);
				tempPlayer = NULL;
			}
			else if (myCho == 2)
			{
				break;
			}
		}
	}
}