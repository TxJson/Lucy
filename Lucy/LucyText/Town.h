#ifndef TOWN_H
#define TOWN_H

#include "pch.h"

#define TOWNNAME "Rackford"
class Town
{
public:
	Town();
	~Town();

	void Run();

private:
	void Introduction();
	void NotAvailable();
	void Dimension();
	void Shop();

	bool myFirstT;
	std::string myChoToConvert;
	int myCho;
};

#endif