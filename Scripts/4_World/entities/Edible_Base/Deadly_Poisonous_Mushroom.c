class Deadly_Poisonous_Mushroom: MushroomBase
{
    override void OnConsume(float amount, PlayerBase consumer)
    {
        super.OnConsume(amount, consumer);
        if (!GetGame().IsServer() || !consumer) return;

        consumer.InsertAgent(eAgents.SALMONELLA, 50);
    }
};
