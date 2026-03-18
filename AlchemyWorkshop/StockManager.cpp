#include "StockManager.h"
#include <string>

void StockManager::initializeStock(std::string potionName)
{
	potionStock.insert(std::make_pair(potionName, 3));
}