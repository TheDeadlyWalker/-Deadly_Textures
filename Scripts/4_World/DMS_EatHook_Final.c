class DMS_Final
{
    static const string TARGET   = "Deadly_Psychedelic_Mushroom";
    static const int    DELAY_MS = 700;
    static const bool   DEBUG_FORCE = false;

    static void MaybeTrip(PlayerBase pl, ItemBase item, string itemType)
    {
        if (!GetGame().IsClient()) return;   // hard-stop on server
        if (!pl) return;
        if (itemType != TARGET) return;

        if (DEBUG_FORCE)
        {
            StartTrip("debug-any-bite");
            return;
        }

        bool last = false;
        if (!item) last = true;
        else if (item.HasQuantity())
        {
            float q = item.GetQuantity();
            if (q <= 0.001) last = true;
        }

        if (!last) return;

        StartTrip("last-bite");
    }

    static void StartTrip(string reason)
    {
        if (!GetGame().IsClient()) return;   // client-only effect

        PPERequester_DMSPsyTrip req;
        Class.CastTo(req, PPERequesterBank.GetRequester(PPERequester_DMSPsyTrip));
        if (!req) return;

        // 60s, 50ms tick, transparent color, gentle blur, tiny chroma, 1.2s final fade
        req.StartTrip(60000, 50, 0.20, 0.34, 0.0035, 1200);
    }
}

modded class ActionEat
{
    override void OnEndClient(ActionData action_data)
    {
        super.OnEndClient(action_data);
        if (!GetGame().IsClient()) return;
        if (!action_data) return;
        if (!action_data.m_Player) return;

        PlayerBase pb = PlayerBase.Cast(action_data.m_Player);
        ItemBase item = action_data.m_MainItem;

        string t = "";
        if (item)
            t = item.GetType();

        GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(DMS_Final.MaybeTrip, DMS_Final.DELAY_MS, false, pb, item, t);
    }
}

modded class ActionEatSmall
{
    override void OnEndClient(ActionData action_data)
    {
        super.OnEndClient(action_data);
        if (!GetGame().IsClient()) return;
        if (!action_data) return;
        if (!action_data.m_Player) return;

        PlayerBase pb = PlayerBase.Cast(action_data.m_Player);
        ItemBase item = action_data.m_MainItem;

        string t = "";
        if (item)
            t = item.GetType();

        GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(DMS_Final.MaybeTrip, DMS_Final.DELAY_MS, false, pb, item, t);
    }
}

modded class ActionEatBig
{
    override void OnEndClient(ActionData action_data)
    {
        super.OnEndClient(action_data);
        if (!GetGame().IsClient()) return;
        if (!action_data) return;
        if (!action_data.m_Player) return;

        PlayerBase pb = PlayerBase.Cast(action_data.m_Player);
        ItemBase item = action_data.m_MainItem;

        string t = "";
        if (item)
            t = item.GetType();

        GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(DMS_Final.MaybeTrip, DMS_Final.DELAY_MS, false, pb, item, t);
    }
}