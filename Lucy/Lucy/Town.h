#ifndef TOWN_H
#define TOWN_H

#define TOWNNAME "Rackford"

class Town
{
public:
	Town();
	~Town();

	void Update();

private:
	void Introduction();
	void NotAvailable();

	bool myFirstT;
	int myCho;
};

#endif