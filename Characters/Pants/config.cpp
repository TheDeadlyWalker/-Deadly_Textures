class CfgPatches
{
	class Deadly_Textures_Pants // Your mod name followed by the main folder name - DO NOT HAVE DUPLICATE NAMES IF YOU HAVE MULTIPLE CONFIGS
	{
		weapons[] = {};
		requiredVersion = 0.1;
		// Below are the required addons that this config needs specifically
		requiredAddons[] = {"DZ_Data","DZ_Characters","DZ_Characters_Pants"};
		units[] = {};
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
