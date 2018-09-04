#ifndef PCH_H
#define PCH_H

#include <memory>
#include <iostream>
#include <string>
#include <windows.h>

inline void Empty()
{
	system("CLS");
}

inline void Print(const std::string someText)
{
	std::cout << someText << std::endl;
}

inline void Print(std::string &someText)
{
	std::cout << someText << std::endl;
}
#endif
