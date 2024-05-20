#pragma once
#include <string>

//if not provided by the developer, 
// the compiler will create an empty DEFAULT constructor (ctor)
//IFF you provide any ctor, 
//  the compiler default ctor will NOT be provided
class Player
{

public:
	//ctors
	Player(std::string tag, float health, float hunger, float armor);
	Player(std::string tag) 
		: mHealth(20), 
		_hunger(20), 
		armor_(0) 
	{
		++numberOfPlayers_;
	}
	
	//getters/setters to ACCESS & CHANGE the fields
	// in a controlled way

	//getters (accessors)
	float Health() const { return mHealth; }
	float GetHunger() const { return _hunger; }
	float Armor() const { return armor_; }

	//what is inline?
	//setters (mutators)
	void Health(float health)
	{
		if(health <= 20 && health >= 0)
			mHealth = health;
	}

	void HUD() const;

	static void Players();

protected:


private:
	static int numberOfPlayers_;
	float mHealth, _hunger, armor_;
	std::string gamerTag_;

	//BEHAVIORS...
	//move, jump, mine, pickup, use, look
	void pickup(std::string object);
};

