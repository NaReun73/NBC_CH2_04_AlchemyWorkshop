#pragma once
#include <string>
#include <map>
#include "PotionRecipe.h"

class StockManager
{
private:
	std::map<std::string, int> potionStock;
	const int MAX_STOCK = 3;

public:
	void initializeStock(const std::string& potionName);
	bool dispensePotion(const std::string& potionName);
	void returnPotion(const std::string& potionName);
	int getStock(const std::string& potionName) const;
};

