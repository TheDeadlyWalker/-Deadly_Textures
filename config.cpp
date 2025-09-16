class CfgPatches
{
	class Deadly_Textures
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = 
		{
			"DZ_Data",
			"DZ_Scripts",
			"Rag_Liquid_Framework"
		};
	};
};
class CfgMods
{
    class Deadly_Textures
    {
        dir = "Deadly_Textures";
        name = "Deadly_Textures";
        author = "Deadly_Walker";
        type = "mod";
		dependencies[] = {"Game","World","Mission"};
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {"Deadly_Textures/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"Deadly_Textures/scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"Deadly_Textures/scripts/5_Mission"};
			};
		};
	};
};
class CfgLiquidDefinitions
{
	class Liquid_Healing_Tea
	{
		type=615;	// integer from constants.c
		displayName="Healing Tea";
		flammability=30;
		liquidBoilingThreshold=150;
		class Nutrition
		{
			fullnessIndex=1;
			energy=0;
			water=80;
			nutritionalIndex=75;
			toxicity=-0.0;
			digestibility=2;
		};
	};
		class Liquid_Energy_Tea
	{
		type=616;	// integer from constants.c
		displayName="Energy Tea";
		flammability=30;
		liquidBoilingThreshold=150;
		class Nutrition
		{
			fullnessIndex=1;
			energy=0;
			water=80;
			nutritionalIndex=75;
			toxicity=-0.0;
			digestibility=2;
		};
	};
		class Liquid_Antibiotic_Tea
	{
		type=617;	// integer from constants.c
		displayName="Antibiotic Tea";
		flammability=30;
		liquidBoilingThreshold=150;
		class Nutrition
		{
			fullnessIndex=1;
			energy=0;
			water=80;
			nutritionalIndex=75;
			toxicity=-0.0;
			digestibility=2;
		};
	};
		class Liquid_Death_Tea
	{
		type=618;	// integer from constants.c
		displayName="Liquid Death";
		flammability=30;
		liquidBoilingThreshold=150;
		class Nutrition
		{
			fullnessIndex=1;
			energy=0;
			water=80;
			nutritionalIndex=75;
			toxicity=-0.0;
			digestibility=2;
		};
	};
};