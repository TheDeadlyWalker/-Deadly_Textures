class CfgPatches
{
	class Deadly_Textures_Drinks
	{
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = 
		{
		"DZ_Data"
		};
		units[] = {};
	};
};
class CfgVehicles
{	
	class WaterPouch_ColorBase;
	class WaterPouch_Mushroom: WaterPouch_ColorBase
	{
		scope=2;
		displayName="Tessa's Flask";
		descriptionShort="A handmade leather pouch for water. (Has a faint scent that's earthy and sweet). ";
		visibilityModifier=0.85000002;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"Deadly_Textures\Gear\Drinks\Data\waterpouch_Mushroom_co.paa",
			"Deadly_Textures\Gear\Drinks\Data\waterpouch_Mushroom_co.paa",
			"Deadly_Textures\Gear\Drinks\Data\waterpouch_Mushroom_co.paa"
		};
	};
};

