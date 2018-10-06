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
		Print("GAME: " NAME, 12);
		Print("Author: " AUTHOR "\n", 12);
		Print("[1] <Start>\n[2] <Exit>\n");

		std::string tempCho;
		std::getline(std::cin, tempCho);

		if (tempCho != "")
		{
			myCho = ConvertToInt(tempCho);

			if (myCho == 1)
			{
				myTown.Run(Player());
			}
			else if (myCho == 2)
			{
				break;
			}
		}
	}
}