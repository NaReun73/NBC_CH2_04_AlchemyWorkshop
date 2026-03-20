#include "AlchemyWorkshop.h"
#include <iostream>

void AlchemyWorkshop::addRecipe(const std::string& name, const std::vector<std::string>& ingredients)
{
    PotionRecipe* newRecipe = recipeManager.addRecipe(name, ingredients);
    if (newRecipe != nullptr)
    {
        std::cout << ">> 새로운 레시피 '" << name << "'이(가) 추가되었습니다." << std::endl;
        stockManager.initializeStock(newRecipe->potionName);
    }
    else
    {
        std::cout << name << "레시피가 이미 존재합니다." << std::endl;
    }
}

const void AlchemyWorkshop::displayAllRecipes()
{
    const auto& allRecipe = recipeManager.getAllRecipes();
    if (allRecipe.empty()) {
        std::cout << "아직 등록된 레시피가 없습니다." << std::endl;
        return;
    }

    std::cout << "\n--- [ 전체 레시피 목록 ] ---" << std::endl;
    for (const auto& recipe : allRecipe)
    {
        int stock = stockManager.getStock(recipe.potionName);
        std::cout << "- 물약 이름: " << recipe.potionName << ", 현재 재고 : "<< stock << std::endl;
        std::cout << "  > 필요 재료: ";

        for (size_t i =0; i < recipe.ingredients.size(); i++)
        {
            std::cout << recipe.ingredients[i] << ", ";
            if (i == recipe.ingredients.size())
            {
                std::cout << recipe.ingredients[i] << "";
            }
        }
        std::cout << std::endl;
    }
    std::cout << "---------------------------\n";
}

void AlchemyWorkshop::searchRecipeByName(const std::string& name)
{
    if (recipeManager.getAllRecipes().empty())
    {
        std::cout << "아직 등록된 레시피가 없습니다." << std::endl;
        return;
    }

    PotionRecipe* recipe = recipeManager.findRecipeByName(name);
    if (recipe == nullptr)
    {
        std::cout << name << "이란 물약은 없습니다." << std::endl;
        return;
    }

    std::cout << name << "을(를) 찾았습니다." << std::endl;

    bool dispense = stockManager.dispensePotion(name);

    if (dispense)
    {
        std::cout << name << "을(를) 모험가에게 지급합니다. (남은 재고 : " << stockManager.getStock(name) << ")" << std::endl;
        return;
    }
    else
    {
        std::cout << name <<"의 재고가 부족합니다." << std::endl;
        return;
    }
}

void AlchemyWorkshop::searchRecipeByIngredient(std::string& ingredient)
{
    if (recipeManager.getAllRecipes().empty())
    {
        std::cout << "아직 등록된 레시피가 없습니다." << std::endl;
        return;
    }

    std::vector<PotionRecipe> searchRecipe = recipeManager.findRecipesByIngredient(ingredient);

    if (searchRecipe.empty())
    {
        std::cout << ingredient << "을(를) 재료로 사용하는 레시피가 없습니다." << std::endl;
        return;
    }
    else
    {
        std::cout << "-" << ingredient << "을(를) 재료로 사용하는 레시피" << std::endl;
        for (const auto& recipe : searchRecipe)
        {
            std::cout <<" >" << recipe.potionName << std::endl;
        }
    }
}

void AlchemyWorkshop::returnPotionByName(const std::string& name)
{
    if (recipeManager.getAllRecipes().empty())
    {
        std::cout << "아직 등록된 레시피가 없습니다." << std::endl;
        return;
    }

    PotionRecipe* recipe = recipeManager.findRecipeByName(name);
    if (recipe == nullptr)
    {
        std::cout << name << "이란 물약은 없습니다." << std::endl;
        return;
    }

    stockManager.returnPotion(name);
}