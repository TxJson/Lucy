#ifndef PCH_H
#define PCH_H

#include <iostream>
#include <string>
#include <windows.h>
#include <thread>
#include <chrono>
#include <iomanip>

inline void Empty()
{
	system("CLS");
}

//Time in milliseconds
inline void Sleep(int someTime)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(someTime));
}

inline void Print(const std::string someText, const int aColourCode = 15)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), aColourCode);
	std::cout << someText << std::endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

inline void Print(std::string &someText, const int aColourCode = 15)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), aColourCode);
	std::cout << someText << std::endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

inline int Randomize(int &aLowAmount, int &aHighAmount)
{
	return (rand() % aHighAmount + aLowAmount);
}

/*
Colour codes

0   BLACK
1   BLUE
2   GREEN
3   CYAN
4   RED
5   MAGENTA
6   BROWN
7   LIGHTGRAY
8   DARKGRAY
9   LIGHTBLUE
10  LIGHTGREEN
11  LIGHTCYAN
12  LIGHTRED
13  LIGHTMAGENTA
14  YELLOW
15  WHITE
+ 241 Others
*/
inline void SetColour(const int aColourCode)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), aColourCode);
}

inline void ResetColour()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

#endif
