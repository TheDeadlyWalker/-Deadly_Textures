class ActionSewSelfSalve : ActionSewSelf
{
    protected float m_QBefore;

    void ActionSewSelfSalve()
    {
        m_Text = "Apply Salve";
    }

    override void CreateConditionComponents()
    {
        m_ConditionItem   = new CCINonRuined();
        m_ConditionTarget = new CCTNone();
    }

    // only when bleeding + has charges
    override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
    {
        if (!player || !item) return false;
        if (item.IsRuined()) return false;
        if (item.GetQuantity() <= 0) return false;
        return player.IsBleeding();
    }

    override void OnStartServer(ActionData action_data)
    {
        super.OnStartServer(action_data);
        ItemBase it = action_data.m_MainItem;
        if (it) m_QBefore = it.GetQuantity();
        else    m_QBefore = 0;
    }

    // force exactly 4 uses + delete on empty + antibiotics
    override void OnFinishProgressServer(ActionData action_data)
    {
        super.OnFinishProgressServer(action_data); // vanilla stitch + default drain

        ItemBase it = action_data.m_MainItem;
        if (it)
        {
            float maxq = it.GetQuantityMax();
            if (maxq <= 0) maxq = 100;

            float targetDrain = maxq / 4.0;
            if (targetDrain < 1.0) targetDrain = 1.0;

            float actualDrain = m_QBefore - it.GetQuantity();
            if (actualDrain < 0.0) actualDrain = 0.0;

            float adjust = targetDrain - actualDrain;

            if (Math.AbsFloat(adjust) > 0.01)
            {
                float newQ = it.GetQuantity() - adjust;
                newQ = Math.Clamp(newQ, 0.0, maxq);
                it.SetQuantity(newQ);
            }

            if (it.GetQuantity() <= 0.001)
            {
                it.SetQuantity(0);          // trigger destroy-on-min
                GetGame().ObjectDelete(it); // hard delete now
            }
        }

        PlayerBase p = PlayerBase.Cast(action_data.m_Player);
        if (p)
        {
            ModifiersManager mm = p.GetModifiersManager();
            if (mm)
            {
                if (mm.IsModifierActive(eModifiers.MDF_ANTIBIOTICS))
                    mm.DeactivateModifier(eModifiers.MDF_ANTIBIOTICS);
                mm.ActivateModifier(eModifiers.MDF_ANTIBIOTICS);
            }
        }
    }
};