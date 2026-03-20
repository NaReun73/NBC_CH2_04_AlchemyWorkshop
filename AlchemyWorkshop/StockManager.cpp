#include "StockManager.h"
#include <iostream>
#include <string>
#include <map>

void StockManager::initializeStock(const std::string& potionName)
{
	potionStock[potionName] = MAX_STOCK;
	std::cout << potionName << "의 재고는 " << MAX_STOCK << "개 있습니다." << std::endl;
}

bool StockManager::dispensePotion(const std::string& potionName)
{
	if (potionStock.find(potionName) != potionStock.end())
	{
		auto& stock = potionStock[potionName];
		if (stock > 0)
		{
			stock--;
			return true;
		}
	}
	return false;
}

void StockManager::returnPotion(const std::string& potionName)
{
	if (potionStock.find(potionName) != potionStock.end())
	{
		auto& stock = potionStock[potionName];
		if (stock < MAX_STOCK)
		{
			stock++;
			std::cout << potionName << "을 반환 받았습니다. (현재 재고 : " << stock << ")" << std::endl;
		}
		else
		{
			std::cout << "최대 재고("<< MAX_STOCK << "개)를 초과할 수 없습니다." << std::endl;
		}
	}
}

int StockManager::getStock(const std::string& potionName) const
{
	auto it = potionStock.find(potionName);
	if (it != potionStock.end()) return it->second;

	return 0;
}