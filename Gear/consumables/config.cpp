class CfgPatches
{
	class Deadly_Textures_Consumables
	{
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = 
		{
		"DZ_Data"
		};
		units[] = {};
	};
};
class CfgVehicles
{	
	class Inventory_Base;
	class Paper: Inventory_Base
	{
		canBeSplit = 1;
		varQuantityInit = 1;
		varQuantityMin = 0;
		varQuantityMax = 5;
		varStackMax = 5;
		varQuantityDestroyOnMin = 1;
	};
	class Syndicate_Pass: Paper
	{
		scope=2;
		displayName="Syndicate_Pass";
		descriptionShort="Paper with a logo and note";
		visibilityModifier=0.85000002;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"Deadly_Textures\Gear\consumables\loot_paper_Syndicate_co.paa",
			"Deadly_Textures\Gear\consumables\loot_paper_Syndicate_co.paa",
			"Deadly_Textures\Gear\consumables\loot_paper_Syndicate_co.paa"
		};
	};
};
