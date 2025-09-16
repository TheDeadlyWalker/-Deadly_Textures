class CfgPatches
{
	class Deadly_Textures_Headgear
	{
		units[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = 
		{
			"DZ_Data",
			"DZ_Characters",
			"DZ_Characters_Headgear"
		};
	};
};
class CfgVehicles
{	
	class WitchHood_ColorBase;
	class Deadly_WitchHood: WitchHood_ColorBase
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
			"Deadly_Textures\Characters\Headgear\Data\witchhood__MushroomLady_co.paa",
			"Deadly_Textures\Characters\Headgear\Data\witchhood__MushroomLady_co.paa",
			"Deadly_Textures\Characters\Headgear\Data\witchhood__MushroomLady_co.paa"
		};

	};			
	class WitchHood_ColorBase;
	class Deadly_WitchHood2: WitchHood_ColorBase
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
			"Deadly_Textures\Characters\Headgear\Data\witchhood_MushroomLady2_co.paa",
			"Deadly_Textures\Characters\Headgear\Data\witchhood_MushroomLady2_co.paa",
			"Deadly_Textures\Characters\Headgear\Data\witchhood_MushroomLady2_co.paa"
		};

	};	
	class WitchHat;
	class Deadly_Witchhat_Mushroom: WitchHat
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
			"Deadly_Textures\Characters\Headgear\Data\witchhat_mushroom_co.paa",
			"Deadly_Textures\Characters\Headgear\Data\witchhat_mushroom_co.paa",
			"Deadly_Textures\Characters\Headgear\Data\witchhat_mushroom_co.paa"
		};

	};			
};
