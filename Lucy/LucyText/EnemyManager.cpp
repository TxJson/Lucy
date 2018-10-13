#include "EnemyManager.h"
#include "File.h"

EnemyManager::EnemyManager()
{
	myFiles = GetXmlFiles(myPath);
	myEnemies.resize(myFiles.size());
	for (size_t x = 0; x < myEnemies.size(); x++)
	{
		myEnemies[x].Name = GetFromXml(myFiles[x], "Name");
		myEnemies[x].ID = ConvertToInt(GetFromXml(myFiles[x], "Id"));
		myEnemies[x].HealthMax = ConvertToInt(GetFromXml(myFiles[x], "Health"));
		myEnemies[x].Health = myEnemies[x].HealthMax;
		myEnemies[x].Damage = ConvertToInt(GetFromXml(myFiles[x], "Damage"));
		myEnemies[x].DropRateChance = std::stof(GetFromXml(myFiles[x], "DropRate")); //std::stof convert from string to float

		for (size_t y = 0; y < 2; y++)
		{
			myEnemies[x].Abilities[y].Name = GetFromXml(myFiles[x], "A" + std::to_string(y));
			myEnemies[x].Abilities[y].Damage = ConvertToInt(GetFromXml(myFiles[x], "A" + std::to_string(y) + "_Damage"));
		}

		myEnemies[x].AliveFlag = true;
	}
}

EnemyManager::~EnemyManager()
{
}

Entity EnemyManager::GetEnemy()
{
	myEnemyID = Randomize(0, (int)myEnemies.size());
	return myEnemies[myEnemyID];
}