#ifndef PCH_H
#define PCH_H

#include <iostream>
#include <string>
#include <list>
#include <windows.h>
#include <thread>
#include <chrono>
#include <iomanip>

enum Colour
{
	BLACK,
	BLUE,
	GREEN,
	CYAN,
	RED,
	MAGENTA,
	BROWN,
	LIGHTGRAY,
	DARKGRAY,
	LIGHTBLUE,
	LIGHTGREEN,
	LIGHTCYAN,
	LIGHTRED,
	LIGHTMAGENTA,
	YELLOW,
	WHITE
};

inline void Empty()
{
	system("CLS");
}

//Time in milliseconds
inline void Sleep(const int &someTime)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(someTime));
}

inline void Print(const std::string &someText, const int &aColourCode = Colour::WHITE)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), aColourCode);
	std::cout << someText << std::endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Colour::WHITE);
}

/*
Must use PrintEnd afterwards or normal print.
*/
inline void PrintCon(const std::string &someText, const int &aColourCode = Colour::WHITE)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), aColourCode);
	std::cout << someText;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Colour::WHITE);
}

inline int Randomize(const int &aLowAmount, const int &aHighAmount)
{
	return (aLowAmount + (rand() % aHighAmount));
}

inline int ConvertToInt(const std::string &aConvertableString)
{
	if (!aConvertableString.empty())
	{
		try
		{
			return std::stoi(aConvertableString);
		}
		catch (...) {}
	}
	return 0;
}

inline void SetColour(const int &aColourCode)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), aColourCode);
}

inline void ResetColour()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

#endif