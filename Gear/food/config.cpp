class CfgPatches
{
    class Deadly_Textures_Food
    {
        units[] = 
        {
            "Deadly_Psychedelic_Mushroom",
            "Deadly_Poisonous_Mushroom",
            "Deadly_Antibiotic_Mushroom",
            "Deadly_Death_Mushroom",
             "Deadly_Space_Shroom",
            "Deadly_PoisonApple"
        };
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = 
        {
            "DZ_Data",
            "DZ_Scripts",
            "DZ_Gear_Food"
        };
    };
};

    class CfgMods
{
    class Deadly_Textures
    {
        type = "mod";
        name = "Deadly_Textures";
        author = "Deadly_Walker";
        dependencies[] = {"Game","World","Mission"};
        class defs
        {
            class gameScriptModule
            {
                files[] = {"Deadly_Textures/scripts/3_Game"};
            };
            class worldScriptModule
            {
                files[] = {"Deadly_Textures/scripts/4_World"};            
            };
            class missionScriptModule
            {
                files[] = {"Deadly_Textures/scripts/5_Mission"};
            };
        };
    };
};

    class CfgVehicles

{
    class AgaricusMushroom;

    class Deadly_Psychedelic_Mushroom: AgaricusMushroom
    {
        scope = 2;
        displayName = "Unusual Mushroom";
        descriptionShort = "A psychedelic-looking mushroom. I'm sure it's fine to eat.";
        visibilityModifier = 0.85;
        hiddenSelectionsTextures[] =
        {
            "Deadly_Textures\Gear\food\Data\mushroom_pycho_co.paa"
        };
        varQuantityInit = 150;
        varQuantityMin  = 0;
        varQuantityMax  = 150;
    };

    class AmanitaMushroom;

    class Deadly_Poisonous_Mushroom: AmanitaMushroom
    {
        scope = 2;
        displayName = "Bright Blue Mushroom";
        descriptionShort = "Yummy Yummy in my Tummy!";
        visibilityModifier = 0.85;
        hiddenSelectionsTextures[] =
        {
            "Deadly_Textures\Gear\food\Data\mushroom_poisonous_co.paa"
        };
    };
        class AuriculariaMushroom;

        class Deadly_Antibiotic_Mushroom: AuriculariaMushroom
    {
        scope = 2;
        displayName = "Healthy Pink Mushroom";
        descriptionShort = "That tastes so good?!";
        visibilityModifier = 0.85;
        hiddenSelectionsTextures[] =
        {
            "Deadly_Textures\Gear\food\Data\mushroom_Antibiotic_co.paa"
        };
    };
        class CraterellusMushroom;

        class Deadly_Death_Mushroom: CraterellusMushroom
    {
        scope = 2;
        displayName = "Deathshroom Mushroom";
        descriptionShort = "It smells like the dead!";
        visibilityModifier = 0.85;
        hiddenSelectionsTextures[] =
        {
            "Deadly_Textures\Gear\food\Data\mushroom_craterellus_black_co.paa"
        };
    };
        class Apple;

        class Deadly_PoisonApple: Apple
    {
        scope = 2;
        displayName = "Suspicious Apple";
        descriptionShort = "The skin is too shiny, the smell a little strange. Best left alone.";
        visibilityModifier = 0.85;
        hiddenSelections[] = {"cs_raw"};
        hiddenSelectionsTextures[] =
        {
            "Deadly_Textures\Gear\food\Data\SWA_Poison_Apple_co.paa"
        };
    };
        class LactariusMushroom;

        class Deadly_Space_Shroom: LactariusMushroom
    {
        scope = 2;
        displayName = "Colourful Shroom";
        descriptionShort = "Just a normal shroom, Maybe if it was boiled correctly!.";
        visibilityModifier = 0.85;
        hiddenSelectionsTextures[] =
        {
            "Deadly_Textures\Gear\food\Data\mushroom_space_co.paa"
        };
    };

};
