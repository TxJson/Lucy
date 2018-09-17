#ifndef WORLD_H
#define WORLD_H

#define TOWNNAME "Rackford"

enum Location
{
	TOWN,
	DIMENSION
};

class World
{
public:
	World();
	~World();

	void Update();

private:
	void Town();
	void Introduction();
	void NotAvailable();

	int
		myAreaSize,
		myPathSize;
	Location myLocation;
	bool myFirstT;
	int myCho;
};

#endif