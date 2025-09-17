modded class ActionDrink
{
    override void OnFinishProgressServer(ActionData action_data)
    {
        super.OnFinishProgressServer(action_data);

        PlayerBase player = PlayerBase.Cast(action_data.m_Player);
        ItemBase item    = ItemBase.Cast(action_data.m_MainItem);
        if (!player || !item) return;
        if (!item.IsLiquidContainer()) return;

        int lt = item.GetLiquidType();
        if (lt != 619) return; // Liquid_Trip_Tea

        PlayerStat<float> comfort = player.GetStatHeatComfort();
        if (comfort) comfort.Add(1.5); 

        PlayerStat<float> buffer = player.GetStatHeatBuffer();
        if (buffer) buffer.Add(25.0); 
    }
}