#include "ItemManager.h"
#include "File.h"

ItemManager::ItemManager()
{
	myFiles = GetXmlFiles(myPath);
	myItems.resize(myFiles.size());
	for (size_t x = 0; x < myItems.size(); x++)
	{
		myItems[x].Name = GetFromXml(myFiles[x], "Name");
		myItems[x].ID = ConvertToInt(GetFromXml(myFiles[x], "Id"));
		myItems[x].DamageMultiplier = ConvertToInt(GetFromXml(myFiles[x], "DamageMultiplier"));
		myItems[x].ProtectionMultiplier = ConvertToInt(GetFromXml(myFiles[x], "ProtectionMultiplier"));
		myItems[x].HealthMultiplier = ConvertToInt(GetFromXml(myFiles[x], "HealthMultiplier"));
		myItems[x].Enchantable = ConvertToInt(GetFromXml(myFiles[x], "Enchantable"));
		myItems[x].HealingConstant = ConvertToInt(GetFromXml(myFiles[x], "HealingConstant"));
		myItems[x].Cost = ConvertToInt(GetFromXml(myFiles[x], "Cost"));

		//Debug
		if (myItems[x].Enchantable)
			Print("0");
		else
			Print("1");

		for (size_t y = 0; y < 2; y++)
		{
			myItems[x].Abilities[y].Name = GetFromXml(myFiles[x], "A" + std::to_string(y));
			myItems[x].Abilities[y].Damage = ConvertToInt(GetFromXml(myFiles[x], "A" + std::to_string(y) + "_Damage"));
		}
	}
}

ItemManager::~ItemManager()
{
}

Entity ItemManager::GetRandomItem()
{
	myItemID = Randomize(0, (int)myItems.size());
	return myItems[myItemID];
}

Entity ItemManager::GetItem(int anId)
{
	return myItems[anId];
}