class CraftSWA_BirchBark_Salve extends RecipeBase
{	
	override void Init()
	{
		m_Name = "Craft Birch Bark Salve";
		m_IsInstaRecipe = false;
		m_AnimationLength = 1.5;
		m_Specialty = 0;

		// Ingredient 0
		m_MinDamageIngredient[0] = -1;
		m_MaxDamageIngredient[0] = -1;
		m_MinQuantityIngredient[0] = 4;
		m_MaxQuantityIngredient[0] = -1;

		// Ingredient 1
		m_MinDamageIngredient[1] = -1;
		m_MaxDamageIngredient[1] = -1;
		m_MinQuantityIngredient[1] = -1;
		m_MaxQuantityIngredient[1] = -1;

		InsertIngredient(0, "Bark_Birch");
		m_IngredientAddHealth[0] = 0;
		m_IngredientSetHealth[0] = -1;
		m_IngredientAddQuantity[0] = -4;
		m_IngredientDestroy[0] = false;
		m_IngredientUseSoftSkills[0] = false;

		// Ingredient 1:
		InsertIngredient(1, "Deadly_Antibiotic_Mushroom");
		m_IngredientAddHealth[1] = 0;
		m_IngredientSetHealth[1] = -1;
		m_IngredientAddQuantity[1] = 0;
		m_IngredientDestroy[1] = true;
		m_IngredientUseSoftSkills[1] = false;

		// ----- RESULT -----
		AddResult("SWA_BirchBark_Salve");

		m_ResultSetFullQuantity[0] = true;   
		m_ResultSetQuantity[0] = -1;
		m_ResultSetHealth[0] = -1;
		m_ResultInheritsHealth[0] = -1;
		m_ResultInheritsColor[0] = -1;
		m_ResultToInventory[0] = -2;         
		m_ResultUseSoftSkills[0] = false;
		m_ResultReplacesIngredient[0] = -1;
	}

	override bool CanDo(ItemBase ingredients[], PlayerBase player)
	{
		return true;
	}

	override void Do(ItemBase ingredients[], PlayerBase player, array<ItemBase> results, float specialty_weight)
	{
		Debug.Log("CraftSWA_BirchBark_Salve completed","recipes");
	}
};
