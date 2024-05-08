#pragma once
#include "MenuItem.h"
class Menu
{
public:
	void AddMenuItem(MenuItem& item);
private:
	std::vector<MenuItem> food;
};

