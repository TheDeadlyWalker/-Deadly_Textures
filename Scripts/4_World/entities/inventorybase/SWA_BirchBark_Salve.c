class SWA_BirchBark_Salve : Inventory_Base
{
    override void EEInit()
    {
        super.EEInit();
        if (GetGame().IsServer()) FixStartingQuantity();
    }

    override void AfterStoreLoad()
    {
        super.AfterStoreLoad();
        if (GetGame().IsServer() && GetQuantity() <= 0) FixStartingQuantity();
    }

    override void OnDebugSpawn()
    {
        super.OnDebugSpawn();
        FixStartingQuantity();
    }

    override void SetActions()
    {
        super.SetActions();
        AddAction(ActionSewSelfSalve);   // Registered custom action
        AddAction(ActionSewTarget);   
    }    

    void FixStartingQuantity()
    {
        float maxq = GetQuantityMax();
        if (maxq <= 0) maxq = 100;
        SetQuantity(maxq);
    }
};