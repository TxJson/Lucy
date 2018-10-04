#include "EnemyManager.h"
#include "FireWitch.h"
#include "IceWitch.h"
#include "BloodWitch.h"
#include "pch.h"


EnemyManager::EnemyManager()
{
}


EnemyManager::~EnemyManager()
{
}

Entity EnemyManager::GetEnemy()
{
	myEnemyID = Randomize(0, 2);
	switch (myEnemyID) 
	{
	case Enemy::FIREWITCH:
		return FireWitch();
		break;
	case Enemy::ICEWITCH:
		return IceWitch();
		break;
	case Enemy::BLOODWITCH:
		return BloodWitch();
		break;
	}
	return Entity();
}
