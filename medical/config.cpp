class CfgMods
{
    class Deadly_Textures_Medical
    {
        dir = "Deadly_Textures";
        type = "mod";
        name = "Deadly Textures";
        author = "DEADLY_WALKER";
        dependencies[] = {"World"};     
        class defs
        {
            class worldScriptModule
            {
                files[] = { "Deadly_Textures/scripts/4_World" };
            };
        };
    };
};
class CfgPatches
{
    class Deadly_Textures_Medical
    {
        units[] = {"SWA_BIRCHBARK_SALVE"};
        requiredAddons[] = 
        {
            "DZ_Data",
            "DZ_Scripts",
            "DZ_Gear_Food"
        };
    };
};
class CfgVehicles
{
    class Inventory_Base;

    class SWA_BirchBark_Salve: Inventory_Base
    {
        scope = 2;
        displayName = "Birch Bark Salve";
        descriptionShort = "A jar of sticky salve to smear over a cut.";
        model = "\dz\gear\food\marmalade.p3d";
        hiddenSelections[] = 
        {
            "zbytek",
            "camo"
        };
        hiddenSelectionsTextures[] = 
        {
            "Deadly_Textures\Gear\medical\data\SWA_Birch_Salve_co.paa"
        };

        itemSize[] = {2,2};
        weight = 250;
        varQuantityInit = 100;
        varQuantityMin = 0;
        varQuantityMax = 100;
        varQuantityDestroyOnMin = 1;
        quantityShow = 1;
        quantityBar  = 1;
    };
};