// AlchemyWorkshop.h

#pragma once
#include <vector>
#include <string>
#include "PotionRecipe.h"

// AlchemyWorkshop 클래스: 레시피 목록을 관리
class AlchemyWorkshop {
private:
    std::vector<PotionRecipe> recipes;

public:
    // addRecipe 메서드: 재료 목록(vector)을 매개변수로 받도록 수정
    void addRecipe(const std::string& name, const std::vector<std::string>& ingredients);

    // 모든 레시피 출력 메서드
    void displayAllRecipes() const;

    // 물약 이름으로 검색
    const PotionRecipe* searchRecipeByName(const std::string& name) const;

    // 물약 재료로 검색, 특정 재료가 들어간 모든 레시피 출력
    std::vector<PotionRecipe> searchRecipeByIngredient(std::string& ingredient);
};
