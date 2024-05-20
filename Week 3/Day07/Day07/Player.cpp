#include "Player.h"
#include <iostream>


Player::Player(std::string tag, float health, float hunger, float armor) :
	gamerTag_(tag)
	,mHealth(health)
	,_hunger(hunger)
	,armor_(armor)
{
	armor_ = armor;
	numberOfPlayers_++;
}

//NON-static methods have a "HIDDEN" parameter called 'this'
//non-static methods can access static and non-static members
void Player::HUD() const
{
	std::cout << "Health: " << mHealth << "\tHunger: " << _hunger << "\tArmor: " << armor_ << "\n";
}

int Player::numberOfPlayers_ = 0;//initialize static fields

//Static methods do NOT have a 'this' parameter
//static methods can ONLY access other static members
void Player::Players()
{
	//std::cout << mHealth;
	std::cout << "The number of players in the game: " << numberOfPlayers_ << "\n";
}

void Player::pickup(std::string object)
{
	std::cout << mHealth;
}
