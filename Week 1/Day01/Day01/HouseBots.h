#pragma once
#include <string>
#include <vector>
class HouseBots
{
public:
	//[return type] name ( any data to send )
	//parameters are variables. type name
	void CleaningBot(std::string roomToClean);//pass-by-value (COPY)

	std::string CookingBot(std::string recipe, std::vector<std::string> ingredients);
};

