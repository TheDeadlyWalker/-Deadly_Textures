modded class ActionDrinkCookingPot
{
    override void OnEndClient(ActionData action_data)
    {
        super.OnEndClient(action_data);
        if (!GetGame() || !GetGame().IsClient()) return;
        if (!action_data) return;

        PlayerBase pb = PlayerBase.Cast(action_data.m_Player);
        ItemBase item = ItemBase.Cast(action_data.m_MainItem);
        if (!pb || !item) return;
        if (!item.IsLiquidContainer()) return;

        int lt = item.GetLiquidType();
        if (lt != 619) return; // Liquid_Trip_Tea

        PPERequester_DMSPsyTrip_2MinIntense req = PPERequester_DMSPsyTrip_2MinIntense.Cast(PPERequesterBank.GetRequester(PPERequester_DMSPsyTrip_2MinIntense));
        if (!req)
        {
            PPERequesterBank.RegisterRequester(PPERequester_DMSPsyTrip_2MinIntense);
            req = PPERequester_DMSPsyTrip_2MinIntense.Cast(PPERequesterBank.GetRequester(PPERequester_DMSPsyTrip_2MinIntense));
        }
        if (!req) return;

        req.StartTrip2MinIntense();
    }
}