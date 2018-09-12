#ifndef WORLD_H
#define WORLD_H
class World
{
public:
	World();
	~World();

	void Update();

private:
	void ComputeWorld();

	int
		myAreaSize,
		myPathSize;
};

#endif