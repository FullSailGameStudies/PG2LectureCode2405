#pragma once
#include "MenuItem.h"
class Menu
{
public:
	void AddMenuItem(const MenuItem& item);
	void Print() const;
private:
	std::vector<MenuItem> food;
};

