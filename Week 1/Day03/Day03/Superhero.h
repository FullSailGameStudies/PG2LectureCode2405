#pragma once
#include <string>
class Superhero
{
public:
	Superhero(std::string superName, std::string secret);

	void ChangeName(std::string newName = "Batman");
private:
	std::string name, secretIdentity;
};

