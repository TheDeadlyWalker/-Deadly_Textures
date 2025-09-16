class CfgPatches
{
	class Deadly_Textures_Vests // Your mod name followed by the main folder name - DO NOT HAVE DUPLICATE NAMES IF YOU HAVE MULTIPLE CONFIGS
	{
		weapons[] = {};
		requiredVersion = 0.1;
		// Below are the required addons that this config needs specifically
		requiredAddons[] = {"DZ_Data","DZ_Characters","DZ_Characters_Vests"};
		units[] = {};
	};
};
class CfgVehicles
{
	class PlateCarrierVest;
	class Deadly_PunisherVest: PlateCarrierVest
	{
		hiddenSelections[]=
		{
			"camoGround",
			"camoMale",
			"camoFemale"
		};
		hiddenSelectionsTextures[]=
		{
			"Deadly_Textures\Characters\vests\data\PunisherVest_co.paa",
			"Deadly_Textures\Characters\vests\data\PunisherVest_co.paa",
			"Deadly_Textures\Characters\vests\data\PunisherVest_co.paa"
		};
	};
};	