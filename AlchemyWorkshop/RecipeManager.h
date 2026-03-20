#pragma once
#include "PotionRecipe.h"
#include <string>
#include <vector>

class RecipeManager
{
private:
	std::vector<PotionRecipe> recipes;

public:
	PotionRecipe* addRecipe(const std::string name, const std::vector<std::string> ingredients);
	PotionRecipe* findRecipeByName(const std::string& name);
	std::vector<PotionRecipe> findRecipesByIngredient(const std::string& ingredient);
	const std::vector<PotionRecipe>& getAllRecipes() const;
};

