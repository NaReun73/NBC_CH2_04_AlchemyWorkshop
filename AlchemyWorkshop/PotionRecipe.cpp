#include "PotionRecipe.h"
#include <iostream>

PotionRecipe::PotionRecipe(const std::string& name, const std::vector<std::string>& ingredients)
	: potionName(name)
	, ingredients(ingredients)
{

}