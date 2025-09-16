class CfgPatches
{
	class Deadly_Textures_Camping // Your mod name followed by the main folder name - DO NOT HAVE DUPLICATE NAMES IF YOU HAVE MULTIPLE CONFIGS
	{
		weapons[] = {};
		requiredVersion = 0.1;
		// Below are the required addons that this config needs specifically
		requiredAddons[] = {"DZ_Data"};
		units[] = {};
	};
};
class CfgVehicles
{	
	class Flag_Base;
	class Flag_Syndicate: Flag_base
	{
		scope=2;
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"Deadly_Textures\Gear\Camping\data\flag_syndicate_co.paa",
			"Deadly_Textures\Gear\Camping\data\flag_syndicate_co.paa",
			"Deadly_Textures\Gear\Camping\data\flag_syndicate_co.paa"
		};
	};
		class Flag_Base;
		class Flag_Tessa: Flag_base
	{
		scope=2;
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"Deadly_Textures\Gear\Camping\data\flag_tessa_co.paa",
			"Deadly_Textures\Gear\Camping\data\flag_tessa_co.paa",
			"Deadly_Textures\Gear\Camping\data\flag_tessa_co.paa"
		};
	};
};

