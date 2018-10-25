#include "EnemyManager.h"
#include "File.h"

EnemyManager::EnemyManager()
{
	myFiles = GetXmlFiles(myPath);
	myEnemies.resize(myFiles.size());
	for (size_t x = 0; x < myEnemies.size(); x++)
	{
		myEnemies[x].SetName(GetFromXml(myFiles[x], "Name"));
		myEnemies[x].SetId(ConvertToInt(GetFromXml(myFiles[x], "Id")));
		myEnemies[x].SetHealthMax(ConvertToInt(GetFromXml(myFiles[x], "Health")));
		myEnemies[x].SetHealth(myEnemies[x].GetHealthMax());
		myEnemies[x].SetDamage(ConvertToInt(GetFromXml(myFiles[x], "Damage")));
		myEnemies[x].SetDropRate(std::stof(GetFromXml(myFiles[x], "DropRate"))); //std::stof convert from string to float
		
		for (int y = 0; y < 2; y++)
		{
			myEnemies[x].ModifyAbilities(y, GetFromXml(myFiles[x], "A" + std::to_string(y)), ConvertToInt(GetFromXml(myFiles[x], "A" + std::to_string(y) + "_Damage")));
		}
		myEnemies[x].SetActiveFlag(true);
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