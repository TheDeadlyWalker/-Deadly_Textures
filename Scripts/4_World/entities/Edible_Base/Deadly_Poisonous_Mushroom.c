class Deadly_Poisonous_Mushroom: MushroomBase
{
    override void OnConsume(float amount, PlayerBase consumer)
    {
        super.OnConsume(amount, consumer);
        if (!GetGame().IsServer() || !consumer) return;

        // Salmonella (tweak strength as you like)
        consumer.InsertAgent(eAgents.SALMONELLA, 50);
    }
};