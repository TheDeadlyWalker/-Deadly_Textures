class CfgPatches
{
	class Deadly_Textures_Containers
	{
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = 
		{"DZ_Data",
			"DZ_Gear_Containers"
		};
		units[] = {};
	};
};
class CfgVehicles
{	
	class FirstAidKit;
	class SWA_FirstAidKit: FirstAidKit
	{
		scope=2;
		displayName="Witch Black Bag";
		descriptionShort="A small bag for all sorts of witchy going ons";
		visibilityModifier=0.85000002;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"Deadly_Textures\Gear\containers\data\SWA_black_medibag_co.paa"
		};
	};
};