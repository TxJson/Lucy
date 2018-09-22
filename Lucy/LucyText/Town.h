#ifndef TOWN_H
#define TOWN_H

#include "pch.h"
#include "Dimension.h"

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
	void OpenDimension();
	void Shop();

	bool myFirstT;
	std::string myChoToConvert;
	int myCho;

	Dimension myDimension;
};

#endif