class CfgPatches
{
	class Deadly_Textures_Belts // Your mod name followed by the main folder name - DO NOT HAVE DUPLICATE NAMES IF YOU HAVE MULTIPLE CONFIGS
	{
		weapons[] = {};
		requiredVersion = 0.1;
		// Below are the required addons that this config needs specifically
		requiredAddons[] = {"DZ_Data","DZ_Characters","DZ_Characters_Belts"};
		units[] = {};
	};
};
class CfgVehicles
{	
	class MilitaryBelt;
	class Deadly_MilitaryBelt_Brown: MilitaryBelt
	{
		scope=2;
		visibilityModifier=0.85000002;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"Deadly_Textures\Characters\Belts\data\mil_belt_Brown_ca.paa",
			"Deadly_Textures\Characters\Belts\data\mil_belt_Brown_ca.paa",
			"Deadly_Textures\Characters\Belts\data\mil_belt_Brown_ca.paa"
		};

	};
	class HipPack_ColorBase;
	class Deadly_HipPack_Supreme: HipPack_ColorBase
	{
		scope=2;
		visibilityModifier=0.85000002;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"Deadly_Textures\Characters\Belts\data\hippack_Supreme_co.paa",
			"Deadly_Textures\Characters\Belts\data\hippack_Supreme_co.paa",
			"Deadly_Textures\Characters\Belts\data\hippack_Supreme_co.paa"
		};

	};			
};			
