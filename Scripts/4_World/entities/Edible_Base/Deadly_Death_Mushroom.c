class Deadly_Death_Mushroom: MushroomBase
{
    protected bool m_EffectsQueued;

    override void EEInit()
    {
        super.EEInit();
        if (!GetGame() || !GetGame().IsServer()) return;

        if (GetQuantity() <= 0.001)
        {
            float maxQ = GetQuantityMax();
            if (maxQ <= 0) maxQ = 150.0;
            SetQuantity(maxQ);
        }

        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(
            Deadly_Death_Mushroom.PostInitQuantityGuard_Static, 0, false, new Param1<ItemBase>(this)
        );
    }

    static void PostInitQuantityGuard_Static(Param1<ItemBase> p)
    {
        ItemBase ib = ItemBase.Cast(p.param1);
        if (!ib || !GetGame() || !GetGame().IsServer()) return;

        if (ib.GetQuantity() <= 0.001)
        {
            float maxQ = ib.GetQuantityMax();
            if (maxQ <= 0) maxQ = 150.0;
            ib.SetQuantity(maxQ);
        }
    }

    // Fire effects only once the mushroom is fully consumed
    override void OnConsume(float amount, PlayerBase consumer)
    {
        super.OnConsume(amount, consumer);
        if (!GetGame() || !GetGame().IsServer() || !consumer) return;

        if (!m_EffectsQueued && GetQuantity() <= 0.001)
        {
            m_EffectsQueued = true;

            // Immediate 10% current-health hit on finish
            ApplyHealthPercentDamage_Static(new Param2<PlayerBase, float>(consumer, 0.10));

            // Cough #1 after the last-bite animation wraps up
            GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(
                Deadly_Death_Mushroom.CoughLater_Static, 2500, false, new Param1<PlayerBase>(consumer)
            );

            // Cough #2 + extra 10% health a bit later
            GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(
                Deadly_Death_Mushroom.CoughAndDamageAgain_Static, 3800, false, new Param2<PlayerBase, float>(consumer, 0.10)
            );
        }
    }


    static void ApplyHealthPercentDamage_Static(Param2<PlayerBase, float> p)
    {
        PlayerBase pb = p.param1;
        float percent = p.param2;
        if (!pb || !pb.IsAlive()) return;

        float currentHealth = pb.GetHealth("", "Health");
        pb.AddHealth("", "Health", -(currentHealth * percent));
    }

    static void CoughLater_Static(Param1<PlayerBase> p)
    {
        PlayerBase pb = p.param1;
        if (!pb || !pb.IsAlive()) return;

        SymptomManager sm = pb.GetSymptomManager();
        if (sm) sm.QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_COUGH);
    }

    static void CoughAndDamageAgain_Static(Param2<PlayerBase, float> p)
    {
        PlayerBase pb = p.param1;
        float percent = p.param2;
        if (!pb || !pb.IsAlive()) return;

        // Extra 10% current-health hit
        float currentHealth = pb.GetHealth("", "Health");
        pb.AddHealth("", "Health", -(currentHealth * percent));

        // Then cough again
        SymptomManager sm = pb.GetSymptomManager();
        if (sm) sm.QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_COUGH);
    }
};
