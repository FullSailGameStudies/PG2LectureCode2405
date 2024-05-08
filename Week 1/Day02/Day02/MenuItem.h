#pragma once
#include <string>
#include <vector>
class MenuItem
{
public:
	//using & here uses Pass By Reference (ALIAS)
	MenuItem(std::string& itemName, std::vector<std::string>& itemIngredients);

	std::string name;
	std::vector<std::string> ingredients;
private:

};

