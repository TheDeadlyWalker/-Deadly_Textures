class CfgPatches
{
	class Deadly_Textures_Cooking // Your mod name followed by the main folder name - DO NOT HAVE DUPLICATE NAMES IF YOU HAVE MULTIPLE CONFIGS
	{
		weapons[] = {};
		requiredVersion = 0.1;
		// Below are the required addons that this config needs specifically
		requiredAddons[] = 
		{
			"DZ_Data"
		};
		units[] = {};
	};
};
class CfgVehicles
{	
	class Cauldron;
	class Deadly_Cauldron: Cauldron
	{
		scope=2;
        displayName="Tessa's Cauldron";
        descriptionShort="Etched with runes and strange symbols...";
		visibilityModifier=0.85000002;
		hiddenSelections[]=
		{ 
            "zbytek"
        };
		hiddenSelectionsTextures[]=
		{
			"Deadly_Textures\Gear\cooking\Data\Deadly_Witch_cauldron_co.paa",
			"Deadly_Textures\Gear\cooking\Data\Deadly_Witch_cauldron_co.paa",
			"Deadly_Textures\Gear\cooking\Data\Deadly_Witch_cauldron_co.paa"
		};
	};
};