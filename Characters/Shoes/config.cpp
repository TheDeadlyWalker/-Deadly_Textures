class CfgPatches
{
	class Deadly_Textures_Shoes // Your mod name followed by the main folder name - DO NOT HAVE DUPLICATE NAMES IF YOU HAVE MULTIPLE CONFIGS
	{
		weapons[] = {};
		requiredVersion = 0.1;
		// Below are the required addons that this config needs specifically
		requiredAddons[] = {"DZ_Data","DZ_Characters","DZ_Characters_Shoes"};
		units[] = {};
	};
};
class CfgVehicles
{	
	class AthleticShoes_ColorBase;
	class Deadly_Red_Trainers: AthleticShoes_ColorBase
	{
		scope=2;
		visibilityModifier=0.85000002;
		hiddenSelections[]=
		{
			"camoGround",
			"camoMale",
			"camoFemale"
		};
		hiddenSelectionsTextures[]=
		{
			"Deadly_Textures\Characters\Shoes\Data\athleticShoes_deadred_co.paa",
			"Deadly_Textures\Characters\Shoes\Data\athleticShoes_deadred_co.paa",
			"Deadly_Textures\Characters\Shoes\Data\athleticShoes_deadred_co.paa"
		};

	};					
};
