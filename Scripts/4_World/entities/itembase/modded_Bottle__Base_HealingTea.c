// ==========================
// Healing, Energy, Antibiotics & Death Tea setup
// ==========================
static const int LIQUID_HEALING_TEA      = 615;
static const int LIQUID_ENERGY_TEA       = 616;
static const int LIQUID_ANTIBIOTICS_TEA  = 617;
static const int LIQUID_DEATH_TEA        = 618; // NEW

// ---------- Energy Tea: stamina regen "buff" ----------
static const float ENERGY_TEA_REGEN_DURATION_S = 30.0; // buff duration
static const float ENERGY_TEA_REGEN_TICK_SEC   = 0.25; // tick interval
static const float ENERGY_TEA_REGEN_PER_SEC    = 12.0; // extra stamina per second

// Track buffs per player (shared across all Bottle_Base instances)
static ref map<PlayerBase, ref Timer> s_EnergyTeaTimers = new map<PlayerBase, ref Timer>();
static ref map<PlayerBase, float>     s_EnergyTeaRemain = new map<PlayerBase, float>();

modded class Bottle_Base
{
    // ---- Energy tea tick must be a METHOD on a Managed script class (this) ----
    void EnergyTea_Regen_Tick(PlayerBase p)
    {
        if (!p) return;

        float remain;
        if (!s_EnergyTeaRemain || !s_EnergyTeaRemain.Find(p, remain)) return;

        StaminaHandler sh = p.GetStaminaHandler();
        if (sh)
        {
            float add = ENERGY_TEA_REGEN_PER_SEC * ENERGY_TEA_REGEN_TICK_SEC;

            // Safe path: SetStamina with cap
            float cur = sh.GetStamina();
            float cap = sh.GetStaminaCap();
            sh.SetStamina(Math.Min(cap, cur + add));
        }

        // countdown
        remain -= ENERGY_TEA_REGEN_TICK_SEC;
        if (remain <= 0.0)
        {
            Timer t;
            if (s_EnergyTeaTimers && s_EnergyTeaTimers.Find(p, t))
            {
                t.Stop();
                s_EnergyTeaTimers.Remove(p);
            }
            if (s_EnergyTeaRemain) s_EnergyTeaRemain.Remove(p);
            return;
        }
        s_EnergyTeaRemain.Set(p, remain);
    }

    override void OnConsume(float amount, PlayerBase consumer)
    {
        super.OnConsume(amount, consumer);
        if (!GetGame().IsServer() || !consumer) return;

        int lt = GetLiquidType();

        // ---- Healing Tea (615): heals on sip ----
        if (lt == LIQUID_HEALING_TEA)
        {
            float m = amount / 50.0; 
            consumer.AddHealth("", "Health", 1.5 * m);
            consumer.AddHealth("", "Blood",  10.0 * m);
            consumer.AddHealth("", "Shock",  1.0 * m);
        }
        // ---- Energy Tea (616): stamina regen buff (no healing) ----
        else if (lt == LIQUID_ENERGY_TEA)
        {
            if (!s_EnergyTeaTimers) s_EnergyTeaTimers = new map<PlayerBase, ref Timer>();
            if (!s_EnergyTeaRemain) s_EnergyTeaRemain = new map<PlayerBase, float>();

            // Refresh/extend duration on each sip
            s_EnergyTeaRemain.Set(consumer, ENERGY_TEA_REGEN_DURATION_S);

            Timer t;
            if (!s_EnergyTeaTimers.Find(consumer, t))
            {
                t = new Timer(CALL_CATEGORY_GAMEPLAY);
                t.Run(ENERGY_TEA_REGEN_TICK_SEC, this, "EnergyTea_Regen_Tick", new Param1<PlayerBase>(consumer), true);
                s_EnergyTeaTimers.Set(consumer, t);
            }
        }
        // ---- Antibiotics Tea (617)
        else if (lt == LIQUID_ANTIBIOTICS_TEA)
        {
            ModifiersManager mm = consumer.GetModifiersManager();
            if (mm)
            {
                mm.ActivateModifier(eModifiers.MDF_ANTIBIOTICS);
            }
        }
        // ---- Death Tea (618): knock out & take 50% of current Blood ----
        else if (lt == LIQUID_DEATH_TEA)
        {
            // Remove 50% of current Blood (no bleeding sources)
            float curBlood = consumer.GetHealth("", "Blood");
            float loss     = curBlood * 0.5;
            consumer.AddHealth("", "Blood", -loss);
            consumer.SetHealth("", "Shock", 0.0);
        }
    }

};
