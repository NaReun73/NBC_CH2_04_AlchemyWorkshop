#include "RecipeManager.h"
#include <string>
#include <vector>
#include <iostream>

PotionRecipe* RecipeManager::addRecipe(const std::string name, const std::vector<std::string> ingredients)
{
    for (auto& recipe : recipes)
    {
        if (recipe.potionName == name)
        {
            return nullptr;
        }
    }
    recipes.push_back(PotionRecipe(name, ingredients));
    return &recipes.back();
}

PotionRecipe* RecipeManager::findRecipeByName(const std::string& name)
{
    if (recipes.empty()) return nullptr;

    for (auto& recipe : recipes)
    {
        if (recipe.potionName == name)
        {
            return &recipe;
        }
    }

    return nullptr;
}

std::vector<PotionRecipe> RecipeManager::findRecipesByIngredient(const std::string& ingredient)
{
    std::vector<PotionRecipe> searcRecipe;

    if (recipes.empty()) return searcRecipe;

    for (const auto& recipe : recipes)
    {
        for (const auto& i : recipe.ingredients)
        {
            if (i == ingredient)
            {
                searcRecipe.push_back(recipe);
            }
        }
    }

    return searcRecipe;
}
const std::vector<PotionRecipe>& RecipeManager::getAllRecipes() const
{
	return recipes;
}