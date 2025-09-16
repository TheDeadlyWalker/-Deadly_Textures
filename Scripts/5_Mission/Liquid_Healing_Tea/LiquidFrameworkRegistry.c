modded class LiquidFrameworkRegistry
{
	override void RegisterCustomLiquids()
	{
		super.RegisterCustomLiquids();
		
		RegisterLiquid(Liquid_Healing_Tea, "Healing Tea", Colors.Liquid_Healing_Tea);
		RegisterLiquid(Liquid_Energy_Tea,  "Energy Tea", Colors.Liquid_Energy_Tea);
		RegisterLiquid(Liquid_Antibiotic_Tea,  "Antibiotic Tea", Colors.Liquid_Antibiotic_Tea);
		RegisterLiquid(Liquid_Death_Tea,  "Liquid Death", Colors.Liquid_Death_Tea);
	}
};