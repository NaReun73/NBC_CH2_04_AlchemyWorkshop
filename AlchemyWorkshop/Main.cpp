#include "AlchemyWorkshop.h"
#include "PotionRecipe.h"
#include <iostream>
#include <vector>
#include <string>

int main() {
    AlchemyWorkshop myWorkshop;

    while (true) {
        std::cout << "******* 연금술 공방 관리 시스템 *******" << std::endl;
        std::cout << "1. 레시피 추가" << std::endl;
        std::cout << "2. 모든 레시피 출력" << std::endl;
        std::cout << "3. 레시피 이름으로 검색" << std::endl;
        std::cout << "4. 특정 재료가 들어가는 모든 레시피 검색" << std::endl;
        std::cout << "5. 종료" << std::endl;
        std::cout << "선택: ";

        int choice;
        std::cin >> choice;
        std::cin.ignore(10000, '\n');

        if (std::cin.fail()) {
            std::cout << "잘못된 입력입니다. 숫자를 입력해주세요." << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        if (choice == 1) {
            std::string name;
            std::cout << "물약 이름: ";
            //std::cin.ignore(10000, '\n');
            std::getline(std::cin, name);

            // 여러 재료를 입력받기 위한 로직
            std::vector<std::string> ingredients_input;
            std::string ingredient;
            std::cout << "필요한 재료들을 입력하세요. (입력 완료 시 '끝' 입력)" << std::endl;

            while (true) {
                std::cout << "재료 입력: ";
                std::getline(std::cin, ingredient);

                // 사용자가 '끝'을 입력하면 재료 입력 종료
                if (ingredient == "끝") {
                    break;
                }
                ingredients_input.push_back(ingredient);
            }

            // 입력받은 재료가 하나 이상 있을 때만 레시피 추가
            if (!ingredients_input.empty()) {
                myWorkshop.addRecipe(name, ingredients_input);
            }
            else {
                std::cout << ">> 재료가 입력되지 않아 레시피 추가를 취소합니다." << std::endl;
            }

        }
        else if (choice == 2) {
            myWorkshop.displayAllRecipes();

        }
        else if (choice == 3)
        {
            std::cout << "레시피의 이름을 적어주세요." << std::endl;
            std::string searchName;
            std::cin.ignore(1000, '\n');
            std::getline(std::cin, searchName);
            if (myWorkshop.searchRecipeByName(searchName) != nullptr)
            {
                std::cout << searchName << " 레시피를 찾았습니다!" << std::endl;
            }
            else
            {
                std::cout << searchName << " 레시피가 존재하지 않습니다." << std::endl;
            }
        }
        else if (choice == 4) {
            std::cout << "재료의 이름을 적어주세요." << std::endl;
            std::string searchIngredient;
            std::cin.ignore(1000, '\n');
            std::getline(std::cin, searchIngredient);

            std::vector<PotionRecipe> searchResults = myWorkshop.searchRecipeByIngredient(searchIngredient);

            if (searchResults.empty())
            {
                std::cout << "해당 재료가 포함된 레시피가 없습니다." << std::endl;
            }
            else
            {
                std::cout << "- " << searchIngredient << "가 포함된 레시피" << std::endl;
                for (const auto& recipe : searchResults)
                {
                    std::cout << " > " << recipe.potionName << std::endl;
                }
            }
        }
        else if (choice == 5) {
            std::cout << "공방 문을 닫습니다..." << std::endl;
            break;

        }
        else {
            std::cout << "잘못된 선택입니다. 다시 시도하세요." << std::endl;
        }
    }

    return 0;
}