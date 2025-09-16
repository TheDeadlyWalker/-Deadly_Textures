class DeadlyKOTask
{
	static const int   KO_DURATION_MS   = 180000; // 3 minutes
	static const float KO_TICK_SEC      = 1.0;    // tick every 1.0s
	static const float KO_INITIAL_SHOCK = -5000.0;
	static const float KO_TICK_SHOCK    = -650.0; // keep them down

	PlayerBase m_Player;
	int        m_EndTime;
	ref Timer  m_Timer;

	void DeadlyKOTask(PlayerBase player)
	{
		m_Player = player;
		m_EndTime = GetGame().GetTime() + KO_DURATION_MS;

		// Immediate lights-out
		if (m_Player) m_Player.AddHealth("", "Shock", KO_INITIAL_SHOCK);

		// Start repeating timer; calls OnTick every KO_TICK_SEC
		m_Timer = new Timer(CALL_CATEGORY_GAMEPLAY);
		m_Timer.Run(KO_TICK_SEC, this, "OnTick", null, /*loop=*/true);
	}

	void OnTick()
	{
		if (!m_Player || !m_Player.IsAlive())
		{
			Stop();
			return;
		}

		if (GetGame().GetTime() >= m_EndTime)
		{
			Stop();
			return;
		}

		// Keep shock suppressed below wake threshold
		m_Player.AddHealth("", "Shock", KO_TICK_SHOCK);
	}

	void Stop()
	{
		if (m_Timer) m_Timer.Stop();
		DeadlyKOManager.Remove(this);
	}
}

class DeadlyKOManager
{
	protected static ref array<ref DeadlyKOTask> s_Tasks;

	static void Start(PlayerBase player)
	{
		if (!player) return;
		if (!s_Tasks) s_Tasks = new array<ref DeadlyKOTask>();

		// Optionally: avoid stacking multiple tasks on the same player
		if (HasActiveTaskFor(player)) return;

		s_Tasks.Insert(new DeadlyKOTask(player));
	}

	static void Remove(DeadlyKOTask task)
	{
		if (!s_Tasks || !task) return;
		int idx = s_Tasks.Find(task);
		if (idx > -1) s_Tasks.Remove(idx);
	}

	protected static bool HasActiveTaskFor(PlayerBase player)
	{
		if (!s_Tasks) return false;
		foreach (DeadlyKOTask t : s_Tasks)
		{
			if (t && t.m_Player == player) return true;
		}
		return false;
	}
};