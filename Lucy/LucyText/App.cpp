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
	while (true)
	{
		Empty();
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
			if (myCho == 1) 
			{
				myTown.Run();
			}
			else if (myCho == 2)
			{
				break;
			}
		}
	}
}
