class Deadly_Antibiotic_Mushroom: MushroomBase
{
    override void OnConsume(float amount, PlayerBase consumer)
    {
        super.OnConsume(amount, consumer);
        if (!GetGame().IsServer() || !consumer) return;

        // Give the player a “INFLUENZA”
        consumer.InsertAgent(eAgents.INFLUENZA, 50);
    }
};
