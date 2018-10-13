#ifndef ENEMYMANAGER_H
#define ENEMYMANAGER_H

#include "Entity.h"
#include <vector>

class EnemyManager
{
public:
	EnemyManager();
	~EnemyManager();

	Entity GetEnemy();

private:
	int myEnemyID;
	std::vector<std::string> myFiles;
	std::vector<Entity> myEnemies;
	std::string myPath = "GameFiles/Enemies";
};

#endif