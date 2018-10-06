#include "EnemyManager.h"
#include "pch.h"
#include "File.h"


EnemyManager::EnemyManager()
{
	myFiles = GetFiles(myPath);
	myEnemies.resize(myFiles.size());
	for (size_t x = 0; x < myEnemies.size(); x++)
	{
		myEnemies[x].Name = GetFromXml(myFiles[x], "Name");
		myEnemies[x].ID = ConvertToInt(GetFromXml(myFiles[x], "Id"));
		myEnemies[x].Health = ConvertToInt(GetFromXml(myFiles[x], "Health"));
		myEnemies[x].Damage = ConvertToInt(GetFromXml(myFiles[x], "Damage"));
		myEnemies[x].DropRateChance = ConvertToInt(GetFromXml(myFiles[x], "DropRate"));

		for (size_t y = 0; y < myEnemies[x].Abilities->length(); y++)
		{
			myEnemies[x].Abilities[y] = GetFromXml(myFiles[x], "A" + std::to_string(y));
		}
	}
}


EnemyManager::~EnemyManager()
{
}

Entity EnemyManager::GetEnemy()
{
	std::cout << std::to_string(myFiles.size()) << std::endl;


	myEnemyID = Randomize(0, myEnemies.size());
	return myEnemies[myEnemyID];
}
