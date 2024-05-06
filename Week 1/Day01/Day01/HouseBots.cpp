#include "HouseBots.h"
#include <iostream>

//DEFINITION (the code)
void HouseBots::CleaningBot(std::string roomToClean)
{
	std::cout << "Cleaning the " << roomToClean << ". wrrrrr....\n";
	std::cout << "DONE! Return to charger." << std::endl;
}

std::string HouseBots::CookingBot(std::string recipe, std::vector<std::string> ingredients)
{
	std::cout << "Cooking the " << recipe << ". wrrrrr....with...\n";
	
	//  for loop
	//for (int i = 0; i < ingredients.size(); i++)
	//{
	//	std::cout << ingredients[i] << "\n";
	//}
	// 
	//  RANGE-BASED for loop
	//for (std::string& ingredient : ingredients)
	//{
	//	std::cout << ingredient << "\n";
	//}
	// 
	// 
	//	ITERATOR for loop
	//		begin() - iterator to the first item
	//		end() - 
	for (auto ingredientIter = ingredients.begin(); ingredientIter != ingredients.end(); ingredientIter++)
	{
		//  * - dereferences the pointer
		std::cout << (*ingredientIter) << "\n";
	}
	std::cout << "DONE! Return to charger." << std::endl;

	return recipe;
}
