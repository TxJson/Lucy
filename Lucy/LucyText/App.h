#ifndef APP_H
#define APP_H

#include "Town.h"
#include "Player.h"

#define NAME "Lucy"
#define VERSION 0.01
#define AUTHOR "Pontuz Klasson"
#define LICENSE "Apache License 2.0"
#define REPOSITORY "https://github.com/Tuz1e/Lucy"

class App
{
public:
	App();
	~App();

	void Menu();
	int myCho;
	Town myTown;
};

#endif