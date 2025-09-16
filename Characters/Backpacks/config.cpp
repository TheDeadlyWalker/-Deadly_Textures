class CfgPatches
{
	class Deadly_Textures_Backpacks // Your mod name followed by the main folder name - DO NOT HAVE DUPLICATE NAMES IF YOU HAVE MULTIPLE CONFIGS
	{
		weapons[] = {};
		requiredVersion = 0.1;
		// Below are the required addons that this config needs specifically
		requiredAddons[] = {"DZ_Data","DZ_Characters","DZ_Characters_Backpacks"};
		units[] = {};
	};
};
class CfgVehicles
{	
	class DryBag_ColorBase;
	class Deadly_Casino_Bag_1: DryBag_ColorBase
	{
		scope=2;
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"Deadly_Textures\Characters\Backpacks\data\DryBag_black1_co.paa",
			"Deadly_Textures\Characters\Backpacks\data\DryBag_black1_co.paa",
			"Deadly_Textures\Characters\Backpacks\data\DryBag_black1_co.paa"
		};
	};
	class DryBag_ColorBase;
	class Deadly_Casino_Bag_2: DryBag_ColorBase
	{
		scope=2;
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"Deadly_Textures\Characters\Backpacks\data\DryBag_black2_co.paa",
			"Deadly_Textures\Characters\Backpacks\data\DryBag_black2_co.paa",
			"Deadly_Textures\Characters\Backpacks\data\DryBag_black2_co.paa"
		};
	};
	class DryBag_ColorBase;
	class Deadly_Casino_Bag_3: DryBag_ColorBase
	{
		scope=2;
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"Deadly_Textures\Characters\Backpacks\data\DryBag_black3_co.paa",
			"Deadly_Textures\Characters\Backpacks\data\DryBag_black3_co.paa",
			"Deadly_Textures\Characters\Backpacks\data\DryBag_black3_co.paa"
		};
	};
	class DryBag_ColorBase;
	class Deadly_Casino_Bag_4: DryBag_ColorBase
	{
		scope=2;
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"Deadly_Textures\Characters\Backpacks\data\DryBag_black4_co.paa",
			"Deadly_Textures\Characters\Backpacks\data\DryBag_black4_co.paa",
			"Deadly_Textures\Characters\Backpacks\data\DryBag_black4_co.paa"
		};
	};
	class DryBag_ColorBase;
	class Deadly_Casino_Bag_5: DryBag_ColorBase
	{
		scope=2;
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"Deadly_Textures\Characters\Backpacks\data\DryBag_black5_co.paa",
			"Deadly_Textures\Characters\Backpacks\data\DryBag_black5_co.paa",
			"Deadly_Textures\Characters\Backpacks\data\DryBag_black5_co.paa"
		};
	};
	class ArmyPouch_ColorBase;
	class Deadly_LV_Pouch: ArmyPouch_ColorBase
	{
		scope=2;
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"Deadly_Textures\Characters\Backpacks\data\ArmyPouch_LV_black_CO.paa",
			"Deadly_Textures\Characters\Backpacks\data\ArmyPouch_LV_black_CO.paa",
			"Deadly_Textures\Characters\Backpacks\data\ArmyPouch_LV_black_CO.paa"
		};
	};
	class ArmyPouch_ColorBase;
	class Deadly_Supreme_Pouch: ArmyPouch_ColorBase
	{
		scope=2;
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"Deadly_Textures\Characters\Backpacks\data\ArmyPouch_Supreme_co.paa",
			"Deadly_Textures\Characters\Backpacks\data\ArmyPouch_Supreme_co.paa",
			"Deadly_Textures\Characters\Backpacks\data\ArmyPouch_Supreme_co.paa"
		};
	};		
};
