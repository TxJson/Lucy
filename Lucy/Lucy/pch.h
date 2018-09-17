#ifndef PCH_H
#define PCH_H

#include <memory>
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

///Time in milliseconds
inline void Sleep(int someTime)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(someTime));
}

inline void Print(const std::string someText)
{
	std::cout << someText << std::endl;
}

inline void Print(std::string &someText)
{
	std::cout << someText << std::endl;
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
	HANDLE tempHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(tempHandle, aColourCode);
}

inline void ResetColour()
{
	HANDLE tempHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(tempHandle, 15);
}

#endif
