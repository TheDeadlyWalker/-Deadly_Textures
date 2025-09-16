class CfgPatches
{
	class Deadly_Textures_Belts
		units[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = 
		{
			"DZ_Data",
			"DZ_Characters",
			"DZ_Characters_Belts"
		};
};
	class CfgVehicles
{	
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
