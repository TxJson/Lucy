#include "EnemyManager.h"
#include "File.h"

EnemyManager::EnemyManager()
{
	myFiles = GetXmlFiles(myPath);
	myEnemies.resize(myFiles.size());
	for (size_t x = 0; x < myEnemies.size(); x++)
	{
		myEnemies[x].Name = GetFromXml(myFiles[x], "Name");
		myEnemies[x].myId = ConvertToInt(GetFromXml(myFiles[x], "Id"));
		myEnemies[x].myHealthMax = ConvertToInt(GetFromXml(myFiles[x], "Health"));
		myEnemies[x].myHealth = myEnemies[x].myHealthMax;
		myEnemies[x].myDamage = ConvertToInt(GetFromXml(myFiles[x], "Damage"));
		myEnemies[x].myDropRate = std::stof(GetFromXml(myFiles[x], "DropRate")); //std::stof convert from string to float

		for (size_t y = 0; y < 2; y++)
		{
			myEnemies[x].myAbilities[y].myName = GetFromXml(myFiles[x], "A" + std::to_string(y));
			myEnemies[x].myAbilities[y].myDamage = ConvertToInt(GetFromXml(myFiles[x], "A" + std::to_string(y) + "_Damage"));
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