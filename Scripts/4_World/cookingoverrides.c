modded class Cooking
{
    // --- Liquid IDs & tuning ---
    static const int   LIQUID_HEALING_TEA     = 615;
    static const int   LIQUID_ENERGY_TEA      = 616;
    static const int   LIQUID_ANTIBIOTICS_TEA = 617;
    static const int   LIQUID_DEATH_TEA       = 618;  // NEW
    static const float TEA_COOK_THRESHOLD     = 40.0; // ~1 minute; tune as needed

    // --- Mushroom class names ---
    static const string CLASS_HEALING_MUSHROOM     = "Deadly_Psychedelic_Mushroom";
    static const string CLASS_ENERGY_MUSHROOM      = "Deadly_Poisonous_Mushroom";
    static const string CLASS_ANTIBIOTIC_MUSHROOM  = "Deadly_Antibiotic_Mushroom";
    static const string CLASS_DEATH_MUSHROOM       = "Deadly_Death_Mushroom"; // NEW

    // --- Internal recipe codes ---
    static const int RECIPE_NONE         = 0;
    static const int RECIPE_HEALING      = 1; // -> 615
    static const int RECIPE_ENERGY       = 2; // -> 616
    static const int RECIPE_ANTIBIOTICS  = 3; // -> 617
    static const int RECIPE_DEATH        = 4; // -> 618 (NEW)

    // Track per-pot state
    static ref map<EntityAI, float> s_TeaProgress    = new map<EntityAI, float>();
    static ref map<EntityAI, int>   s_PendingRecipe  = new map<EntityAI, int>();

    override int CookWithEquipment(ItemBase cooking_equipment, float cooking_time_coef = 1)
    {
        int result = super.CookWithEquipment(cooking_equipment, cooking_time_coef);

        // --- Cauldron-only gate ---
        Cauldron pot;
        if (!(cooking_equipment && cooking_equipment.IsKindOf("Deadly_Cauldron") && Class.CastTo(pot, cooking_equipment)))
        {
            if (s_TeaProgress && s_TeaProgress.Contains(cooking_equipment))
                s_TeaProgress.Remove(cooking_equipment);
            if (s_PendingRecipe && s_PendingRecipe.Contains(cooking_equipment))
                s_PendingRecipe.Remove(cooking_equipment);
            return result;
        }

        // Must be water & non-empty to boil into tea
        if (pot.GetQuantity() <= 0 || pot.GetLiquidType() != LIQUID_WATER)
        {
            ResetPotState(pot);
            return result;
        }

        // Determine/lock recipe for this pot
        int recipe = RECIPE_NONE;
        if (s_PendingRecipe && s_PendingRecipe.Contains(pot))
        {
            recipe = s_PendingRecipe.Get(pot);
            if (!HasMushroomForRecipe(pot, recipe))
            {
                ResetPotState(pot);
                recipe = RECIPE_NONE;
            }
        }
        else
        {
            recipe = GetAvailableRecipe(pot);
            if (recipe != RECIPE_NONE)
                s_PendingRecipe.Set(pot, recipe); // lock recipe so it can't swap mid-boil
        }

        if (recipe == RECIPE_NONE)
        {
            ResetPotState(pot);
            return result;
        }

        // Accumulate boil progress
        float progress = 0.0;
        if (s_TeaProgress && s_TeaProgress.Contains(pot))
            progress = s_TeaProgress.Get(pot);

        progress += cooking_time_coef;
        s_TeaProgress.Set(pot, progress);

        // Complete craft if threshold reached
        if (progress >= TEA_COOK_THRESHOLD)
        {
            bool consumed = ConsumeMushroomForRecipe(pot, recipe);

            if (consumed && pot.GetQuantity() > 0 && pot.GetLiquidType() == LIQUID_WATER)
            {
                int target_liquid;
                if (recipe == RECIPE_HEALING)
                    target_liquid = LIQUID_HEALING_TEA;
                else if (recipe == RECIPE_ENERGY)
                    target_liquid = LIQUID_ENERGY_TEA;
                else if (recipe == RECIPE_ANTIBIOTICS)
                    target_liquid = LIQUID_ANTIBIOTICS_TEA;
                else
                    target_liquid = LIQUID_DEATH_TEA; // NEW

                pot.SetLiquidType(target_liquid);
                pot.SetQuantity(pot.GetQuantityMax()); // optional: fill fully
            }

            ResetPotState(pot); // clear progress & recipe regardless
        }

        return result;
    }

    // --------------------
    // Recipe determination
    // --------------------
    protected int GetAvailableRecipe(EntityAI pot)
    {
        // Priority order (top wins if multiple shrooms are present):
        // Healing -> Energy -> Antibiotics -> Death. Adjust to taste.
        if (HasMushroomClassInPot(pot, CLASS_HEALING_MUSHROOM))
            return RECIPE_HEALING;
        if (HasMushroomClassInPot(pot, CLASS_ENERGY_MUSHROOM))
            return RECIPE_ENERGY;
        if (HasMushroomClassInPot(pot, CLASS_ANTIBIOTIC_MUSHROOM))
            return RECIPE_ANTIBIOTICS;
        if (HasMushroomClassInPot(pot, CLASS_DEATH_MUSHROOM))
            return RECIPE_DEATH;
        return RECIPE_NONE;
    }

    protected bool HasMushroomForRecipe(EntityAI pot, int recipe)
    {
        if (recipe == RECIPE_HEALING)
            return HasMushroomClassInPot(pot, CLASS_HEALING_MUSHROOM);
        if (recipe == RECIPE_ENERGY)
            return HasMushroomClassInPot(pot, CLASS_ENERGY_MUSHROOM);
        if (recipe == RECIPE_ANTIBIOTICS)
            return HasMushroomClassInPot(pot, CLASS_ANTIBIOTIC_MUSHROOM);
        if (recipe == RECIPE_DEATH)
            return HasMushroomClassInPot(pot, CLASS_DEATH_MUSHROOM);
        return false;
    }

    protected bool ConsumeMushroomForRecipe(EntityAI pot, int recipe)
    {
        string classname;
        if (recipe == RECIPE_HEALING)
            classname = CLASS_HEALING_MUSHROOM;
        else if (recipe == RECIPE_ENERGY)
            classname = CLASS_ENERGY_MUSHROOM;
        else if (recipe == RECIPE_ANTIBIOTICS)
            classname = CLASS_ANTIBIOTIC_MUSHROOM;
        else
            classname = CLASS_DEATH_MUSHROOM;

        if (ConsumeMushroomOfClassFromCargo(pot, classname))
            return true;
        return ConsumeMushroomOfClassFromAttachments(pot, classname);
    }

    // ---------------
    // State helpers
    // ---------------
    protected void ResetPotState(EntityAI pot)
    {
        if (s_TeaProgress && s_TeaProgress.Contains(pot))
            s_TeaProgress.Remove(pot);
        if (s_PendingRecipe && s_PendingRecipe.Contains(pot))
            s_PendingRecipe.Remove(pot);
    }

    // ----------------------------
    // Generic presence/consume APIs
    // ----------------------------
    protected bool HasMushroomClassInPot(EntityAI container, string classname)
    {
        return HasMushroomOfClassInCargo(container, classname) || HasMushroomOfClassInAttachments(container, classname);
    }

    protected bool HasMushroomOfClassInCargo(EntityAI container, string classname)
    {
        CargoBase cargo = container.GetInventory().GetCargo();
        if (!cargo) return false;

        int count = cargo.GetItemCount();
        for (int i = 0; i < count; i++)
        {
            EntityAI e = cargo.GetItem(i);
            if (e && e.IsKindOf(classname) && !e.IsRuined())
                return true;
        }
        return false;
    }

    protected bool HasMushroomOfClassInAttachments(EntityAI container, string classname)
    {
        int attCount = container.GetInventory().AttachmentCount();
        for (int i = 0; i < attCount; i++)
        {
            EntityAI e = container.GetInventory().GetAttachmentFromIndex(i);
            if (e && e.IsKindOf(classname) && !e.IsRuined())
                return true;
        }
        return false;
    }

    protected bool ConsumeMushroomOfClassFromCargo(EntityAI container, string classname)
    {
        CargoBase cargo = container.GetInventory().GetCargo();
        if (!cargo) return false;

        int count = cargo.GetItemCount();
        for (int i = 0; i < count; i++)
        {
            EntityAI e = cargo.GetItem(i);
            if (e && e.IsKindOf(classname) && !e.IsRuined())
            {
                e.Delete();
                return true;
            }
        }
        return false;
    }

    protected bool ConsumeMushroomOfClassFromAttachments(EntityAI container, string classname)
    {
        int attCount = container.GetInventory().AttachmentCount();
        for (int i = 0; i < attCount; i++)
        {
            EntityAI e = container.GetInventory().GetAttachmentFromIndex(i);
            if (e && e.IsKindOf(classname) && !e.IsRuined())
            {
                e.Delete();
                return true;
            }
        }
        return false;
    }
};