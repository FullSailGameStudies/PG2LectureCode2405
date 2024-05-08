#include "Menu.h"

void Menu::AddMenuItem(const MenuItem& item)
{
	food.push_back(item);
}

//Print is NOT ALLOWED to modify the class OR call
// any non-const methods of the class
void Menu::Print() const
{
	for (size_t i = 0; i < food.size(); i++)
	{

	}
}
