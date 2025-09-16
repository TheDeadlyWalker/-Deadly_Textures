class CfgPatches
{
	class Deadly_Textures_Vests
	{
		units[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = 
		{
		"DZ_Data",
		"DZ_Characters",
		"DZ_Characters_Vests"
		};
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
