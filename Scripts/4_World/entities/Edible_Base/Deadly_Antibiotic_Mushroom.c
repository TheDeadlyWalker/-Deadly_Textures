class Deadly_Antibiotic_Mushroom: MushroomBase
{
    override void OnConsume(float amount, PlayerBase consumer)
    {
        super.OnConsume(amount, consumer);
        if (!GetGame().IsServer() || !consumer) return;

        // Give the player a “cold/flu” agent
        consumer.InsertAgent(eAgents.INFLUENZA, 50); // 50 = dose; tune to taste
    }
};