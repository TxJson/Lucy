#ifndef PCH_H
#define PCH_H

#include <memory>
#include <iostream>
#include <string>
#include <thread>
#include <chrono>

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

inline void ThreadSleep(const int someTime) 
{
	std::this_thread::sleep_for(std::chrono::milliseconds(someTime));
}

inline int GetRand() 
{
	return 10;
}

#endif
