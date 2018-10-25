#include "ItemManager.h"
#include "File.h"

ItemManager::ItemManager()
{
	myFiles = GetXmlFiles(myPath);
	myItems.resize(myFiles.size());
	for (size_t x = 0; x < myItems.size(); x++)
	{
		myItems[x].SetName(GetFromXml(myFiles[x], "Name"));
		myItems[x].SetId(ConvertToInt(GetFromXml(myFiles[x], "Id")));
		myItems[x].SetItemType((ItemTypes)ConvertToInt(GetFromXml(myFiles[x], "Type")));
		myItems[x].SetDamageMultiplier(ConvertToInt(GetFromXml(myFiles[x], "DamageMultiplier")));
		myItems[x].SetProtectionMultiplier(ConvertToInt(GetFromXml(myFiles[x], "ProtectionMultiplier")));
		myItems[x].SetHealthMultiplier(ConvertToInt(GetFromXml(myFiles[x], "HealthMultiplier")));
		myItems[x].SetEnchantable(ConvertToInt(GetFromXml(myFiles[x], "Enchantable")));
		myItems[x].SetHealingConstant(ConvertToInt(GetFromXml(myFiles[x], "HealingConstant")));
		myItems[x].SetCost(ConvertToInt(GetFromXml(myFiles[x], "Cost")));
		myItems[x].SetValue(ConvertToInt(GetFromXml(myFiles[x], "Cost")) / 2);
		myItems[x].SetActiveFlag(true);

		for (int y = 0; y < 2; y++)
		{
			myItems[x].ModifyAbilities(y, GetFromXml(myFiles[x], "A" + std::to_string(y)), ConvertToInt(GetFromXml(myFiles[x], "A" + std::to_string(y) + "_Damage")));
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