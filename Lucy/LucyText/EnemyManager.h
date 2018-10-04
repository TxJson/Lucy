#ifndef ENEMYMANAGER_H
#define ENEMYMANAGER_H

#include "Entity.h"

enum Enemy
{
	FIREWITCH,
	ICEWITCH,
	BLOODWITCH
};

class EnemyManager
{
public:
	EnemyManager();
	~EnemyManager();

	Entity GetEnemy();

	int myEnemyID;
};

#endif