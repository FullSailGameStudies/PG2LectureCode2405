// Day05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <iomanip>

enum class Weapon
{
	Sword, Axe, Spear, Mace
};

int LinearSearch(const std::vector<int>& nummies, int searchTerm)
{
	int index = -1;//-1 indicates not found
	for (size_t i = 0; i < nummies.size(); i++)
	{
		if (searchTerm == nummies[i])
		{
			index = i;
			break;
		}
	}
	return index;
}

void PrintGrades(const std::map<std::string, float>& course)
{
	std::cout << "\nPG2 Grades for 2405\n";
	for (auto& [student,grade] : course)
	{
		std::cout << std::setw(15) << std::left << student;
		std::cout << std::setw(7) << std::right << grade << "\n";
	}
	std::cout << "\n";
}

int main()
{
	/*
		╔═════════╗
		║Searching║
		╚═════════╝

		There are 2 ways to search a vector: linear search or binary search

		CHALLENGE 1:

			write a method to linear search the numbers list.
				The method should take 2 parameters: vector of ints to search, int to search for.
				The method should return -1 if NOT found or the index if found.

			The algorithm:
				1) start at the beginning of the vector
				2) compare each item in the vector to the search item
				3) if found, return the index
				4) if reach the end of the vector, return -1 which means not found

	*/
	//Performance. 
	//how many items, worst case, do we have to look at? 7
	//size() == 7. N = size()
	//O(N)  Linear
	std::vector<int> numbers = { 0,1,2,3,4,5,6 };
	int searchNumber = 3;
	int answer = LinearSearch(numbers, searchNumber);
	if (answer == -1)
		std::cout << searchNumber << " was not found.\n";
	else
		std::cout << searchNumber << " was found at index " << answer << "\n";


	/*
		╔═══════════════════╗
		║ map<TKey, TValue> ║
		╚═══════════════════╝

		[  Creating a map  ]

		map<TKey, TValue>  - an associative collection.
			TKey is a placeholder for the type of the keys.
			TValue is a placeholder for the type of the values.

		When you want to create a map variable,
			1) replace TKey with whatever type of data you want to use for the keys
			2) replace TValue with the type you want to use for the values


		[  Adding items to a map  ]

		There are 2 ways to add items to a map:
		1) using the insert method. (will NOT overwrite)
		2) using [key] = value  (will OVERWRITE any existing value for that key)
	*/
	std::map<std::string,float> menu;
	menu["Lobster Thermidor"] = 36.99;
	menu["Risotto"] = 14.99;

	//std::pair has 2 parts -- first, second
	std::pair<std::string, float> itemToInsert = std::make_pair("Dino Nuggies", 6.99);
	auto wasInserted = menu.insert(itemToInsert);
	//wasInserted has 2 parts
	//	first is the iterator to the item in the map
	//  second is a bool saying whether it was inserted
	if(wasInserted.second == false)
	{
		std::cout << "Dino Nuggies is already on the menu! The price was not updated.\n";
	}


	std::string menuItemToFind = "Chick'n Nuggies";
	//float nuggiePrice = menu[menuItemToFind];//????

	auto foundMenuItem = menu.find(menuItemToFind);
	if (foundMenuItem == menu.end())
		std::cout << menuItemToFind << " is not on the menu. Try McDonald's\n";
	else
	{
		float oldPrice = foundMenuItem->second;
		foundMenuItem->second = oldPrice * 1.05; //update the value
		std::cout << "Yes! we do have " << menuItemToFind;
		std::cout << ". It used to costs " << oldPrice << ".\n";
		std::cout << "Now it costs " << menu[menuItemToFind] << "!! Thanks Putin!\n";
	}




	std::map<Weapon, int> dorasBackpack;//will store the counts of each kind of weapon

	//returns an iterator and a bool. 
	//if the key is already in the map, it will NOT insert it -- the bool will be false.
	auto inserted = dorasBackpack.insert(std::make_pair(Weapon::Sword, 5));
	if (inserted.second == false) //meaning not inserted
		std::cout << "The key was already in the map. It was not inserted.\n";
	else
		std::cout << "The key was inserted in the map.\n";

	dorasBackpack[Weapon::Axe] = 3;
	dorasBackpack[Weapon::Axe] = 7;//simply overwrites the value if the key is already in the map


	/*
		CHALLENGE 2:

			Create a map that stores names (string) and grades. Call the variable grades.
			Add students and grades to your map.

	*/
	std::map<std::string, float> grades;
	std::vector<std::string> students{
		"Justin","Amata","Lucian","Dakota","Aidon","Shaq","Sky","Kinkayde","Luis","J","Devon","Joshua T","Angel","Breanna","Jessica","Joshua N", "Robert","Terrence"

	};
	srand(time(NULL));
	for (auto& student : students)
	{
		grades[student] = (rand() % 10001) / 100.0F;
	}

	std::cout << "\n\nLooping with iterators\n";
	for (auto i = menu.begin(); i != menu.end(); i++)
	{
		//i points to the pairs in the map
		//the first is the key
		//the second is the value
		std::string name = i->first;
		float price = i->second;

		std::cout << std::setw(20) << std::left << name;
		std::cout << std::setw(8) << std::right << price << "\n";
	}

	std::cout << "\n\nLooping with range-based for\n";
	for (auto& [name,price] : menu)
	{
		std::cout << std::setw(20) << std::left << name;
		std::cout << std::setw(8) << std::right << price << "\n";
	}

	std::cout << "\n\n";


	PrintGrades(grades);



	/*
		╔═══════════════════╗
		║ map<TKey, TValue> ║
		╚═══════════════════╝

		[  Looping over a map  ]

		You should use a ranged-based for loop when needing to loop over the entire map.

	*/
	for (auto const& [key, val] : dorasBackpack) //requires C++ 20
	{
		switch (key)
		{
		case Weapon::Sword:
			std::cout << "Sword: ";
			break;
		case Weapon::Axe:
			std::cout << "Axe: ";
			break;
		case Weapon::Spear:
			std::cout << "Spear: ";
			break;
		case Weapon::Mace:
			std::cout << "Mace: ";
			break;
		default:
			break;
		}
		std::cout << val << "\n";
	}


	/*
		CHALLENGE 4:

			Loop over your grades map and print each student name and grade.

	*/



	/*
		╔═══════════════════╗
		║ map<TKey, TValue> ║
		╚═══════════════════╝

		[  Checking for a key in a map  ]

		use the find method to check if the key is in the map

		will return map.end() if NOT found.

	*/
	std::map<Weapon, int>::iterator foundIter = dorasBackpack.find(Weapon::Mace);
	if (foundIter == dorasBackpack.end()) //meaning it was NOT found
	{
		std::cout << "Dora did not find any maces.\n";
	}
	else
	{
		//can safely grab the value for the key
		std::cout << "Dora found " << foundIter->second << " Maces\n";
	}



	/*
		CHALLENGE 5:

			look for a specific student in the map.
			If the student is found, print out the student's grade
			else print out a message that the student was not found

	*/




	/*
		╔═══════════════════╗
		║ map<TKey, TValue> ║
		╚═══════════════════╝

		[  Updating a value for a key in a map  ]

		To update an exisiting value in the map, use the [ ]


	*/
	dorasBackpack[Weapon::Axe] = 1;//updates the count for the axe



	/*
		CHALLENGE 6:

			Pick any student and curve the grade (add 5) that is stored in the grades map

	*/
}