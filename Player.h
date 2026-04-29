#pragma once
#include "PokeMap(Arcadia).h"

class GenericPlayer : public Map		//class for both player and computer players
{
public:
	GenericPlayer(const string& name = "");
	virtual ~GenericPlayer();
	vector<Pokemon*> pokeInventory;
	vector<string> BadgeCase;
	void getPokeInventory();
	void getBadges();
	Room* pLoc;


	string GetName();		//accessor function included to display Players name


protected:
	string m_Name;
};

GenericPlayer::GenericPlayer(const string& name)
{
	m_Name = name;
	pLoc = mStart;
}

string GenericPlayer::GetName()
{
	return m_Name;
}

void GenericPlayer::getPokeInventory()
{
	vector<Pokemon*>::const_iterator iter;
	if (pokeInventory.size() != 0)
	{
		cout << "\nInventory List:" << endl;
		for (iter = pokeInventory.begin(); iter != pokeInventory.end(); ++iter)
		{
			cout << (*iter)->m_Name  << " Health: " << (*iter)->m_Health << endl;
		}
	}
	else
		cout << "\nInventory is Empty! :'( \n";
}

void GenericPlayer::getBadges()
{
	vector<string>::const_iterator iter;

	if (BadgeCase.size() != 0)
	{
		cout << "\nBadges:" << endl;
		for (iter = BadgeCase.begin(); iter != BadgeCase.end(); ++iter)
		{
			cout << *iter << endl;
		}
	}
	else
		cout << "\nYou have no badges! :'( \n";

}

GenericPlayer::~GenericPlayer()
{}

class Player : public GenericPlayer
{
public:
	Player(const string& name = "");
	virtual ~Player();

};

Player::Player(const string& name) :
	GenericPlayer(name)
{}

Player::~Player()
{}

class CompPlayer : public GenericPlayer
{
public:
	CompPlayer(const string& name = "");

	bool Defeated = false;
	
	Room* pGymLoc1 = GymLeader_1_Start;
	Room* pGymLoc2 = GymLeader_2_Start;
	Room* pGymLoc3 = GymLeader_3_Start;
	Room* pGymLoc4 = GymLeader_4_Start;
	Room* pChampLoc1 = Champion_Start;
	virtual ~CompPlayer();

};

CompPlayer::CompPlayer(const string& name):
	GenericPlayer(name)
{}

CompPlayer::~CompPlayer()
{}
