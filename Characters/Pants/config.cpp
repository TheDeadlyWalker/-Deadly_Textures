class CfgPatches
{
	class Deadly_Textures_Pants
		units[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = 
		{
		"DZ_Data",
		"DZ_Characters",
		"DZ_Characters_Pants"
		};
	};
};
class CfgVehicles
{	
	class HunterPants_ColorBase;
	class Deadly_HunterPants_Pale_Green: HunterPants_ColorBase
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
			"Deadly_Textures\Characters\Pants\data\HunterPants_Pale_Green_co.paa",
			"Deadly_Textures\Characters\Pants\data\HunterPants_Pale_Green_co.paa",
			"Deadly_Textures\Characters\Pants\data\HunterPants_Pale_Green_co.paa"
		};

	};		
	class TrackSuitPants_ColorBase;
	class Deadly_Tracksuit_Pants_Burb: TrackSuitPants_ColorBase
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
			"Deadly_Textures\Characters\Pants\data\TrackSuit_Pants_Burb_co.paa",
			"Deadly_Textures\Characters\Pants\data\TrackSuit_Pants_Burb_co.paa",
			"Deadly_Textures\Characters\Pants\data\TrackSuit_Pants_Burb_co.paa"
		};

	};
	class TrackSuitPants_ColorBase;
	class Deadly_Tracksuit_Pants_Burb_Blue: TrackSuitPants_ColorBase
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
			"Deadly_Textures\Characters\Pants\data\TrackSuit_Pants_Burb_blue_co.paa",
			"Deadly_Textures\Characters\Pants\data\TrackSuit_Pants_Burb_blue_co.paa",
			"Deadly_Textures\Characters\Pants\data\TrackSuit_Pants_Burb_blue_co.paa"
		};

	};
	class TrackSuitPants_ColorBase;
	class Deadly_Tracksuit_Pants_Burb_Green: TrackSuitPants_ColorBase
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
			"Deadly_Textures\Characters\Pants\data\TrackSuit_Pants_Burb_green_co.paa",
			"Deadly_Textures\Characters\Pants\data\TrackSuit_Pants_Burb_green_co.paa",
			"Deadly_Textures\Characters\Pants\data\TrackSuit_Pants_Burb_green_co.paa"
		};

	};					
};
