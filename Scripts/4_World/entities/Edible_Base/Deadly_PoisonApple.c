class Deadly_PoisonApple : Apple
{
	override void OnConsume(float amount, PlayerBase consumer)
	{
		super.OnConsume(amount, consumer);
		if (!consumer) return;

		if (GetGame().IsServer())
		{
			DeadlyKOManager.Start(consumer);
		}
	}
};
