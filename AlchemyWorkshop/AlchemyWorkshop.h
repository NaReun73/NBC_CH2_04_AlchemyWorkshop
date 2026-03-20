// AlchemyWorkshop.h

#pragma once
#include <vector>
#include <string>
#include "RecipeManager.h"
#include "StockManager.h"

class AlchemyWorkshop {
private:
    RecipeManager recipeManager;
    StockManager stockManager;


public:
    // 레시피 추가
    void addRecipe(const std::string& name, const std::vector<std::string>& ingredients);

    // 모든 레시피 출력 메서드
    const void displayAllRecipes();

    // 물약 이름으로 검색, 지급
    void searchRecipeByName(const std::string& name);

    // 물약 재료로 검색, 특정 재료가 들어간 모든 레시피 출력
    void searchRecipeByIngredient(std::string& ingredient);

    // 물약 반환
    void returnPotionByName(const std::string& name);
};
