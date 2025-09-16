class CfgPatches
{
	class Deadly_Textures_Shoes
	{
		units[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = 
		{
		"DZ_Data",
		"DZ_Characters",
		"DZ_Characters_Shoes"
		};
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
