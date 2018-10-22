#include "ItemManager.h"
#include "File.h"

ItemManager::ItemManager()
{
	myFiles = GetXmlFiles(myPath);
	myItems.resize(myFiles.size());
	for (size_t x = 0; x < myItems.size(); x++)
	{
		myItems[x].Name = GetFromXml(myFiles[x], "Name");
		myItems[x].myId = ConvertToInt(GetFromXml(myFiles[x], "Id"));
		myItems[x].myItemType = (ItemTypes)ConvertToInt(GetFromXml(myFiles[x], "Type"));
		myItems[x].myDamageMultiplier = ConvertToInt(GetFromXml(myFiles[x], "DamageMultiplier"));
		myItems[x].myProtectionMultiplier = ConvertToInt(GetFromXml(myFiles[x], "ProtectionMultiplier"));
		myItems[x].myHealthMultiplier = ConvertToInt(GetFromXml(myFiles[x], "HealthMultiplier"));
		myItems[x].myEnchantable = ConvertToInt(GetFromXml(myFiles[x], "Enchantable"));
		myItems[x].myHealingConstant = ConvertToInt(GetFromXml(myFiles[x], "HealingConstant"));
		myItems[x].myCost = ConvertToInt(GetFromXml(myFiles[x], "Cost"));

		//Debug
		if (myItems[x].myEnchantable)
			Print("0");
		else
			Print("1");

		for (size_t y = 0; y < 2; y++)
		{
			myItems[x].myAbilities[y].myName = GetFromXml(myFiles[x], "A" + std::to_string(y));
			myItems[x].myAbilities[y].myDamage = ConvertToInt(GetFromXml(myFiles[x], "A" + std::to_string(y) + "_Damage"));
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

Entity ItemManager::GetItemByType(ItemTypes aType)
{
	std::vector<Entity> tempEntityOfType;
	for (size_t i = 0; i < myItems.size(); i++)
	{
		if (myItems.at(i).GetItemType() == aType)
		{
			tempEntityOfType.push_back(myItems.at(i));
		}
	}
	return (tempEntityOfType.size() > 0) ? tempEntityOfType.at(Randomize(0, (int)tempEntityOfType.size())) : myItems.at(0);
}