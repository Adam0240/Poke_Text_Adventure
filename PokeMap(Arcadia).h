#include <iostream>
#include <string>
#include <vector>
#include "Player.h"
#include"Poke.h"

using namespace std;

class Room
{
public:
	Room(string n, string desc);

	vector<Pokemon*> RoomPokeInventory;

	void setRoomPokemon(Pokemon* poke);
	void getRoomTrainer();
	void getRoomPokeInventory();

	void pRoomName();
	void pRoomDesc();

	Room* pEast;
	Room* pWest;
	Room* pNorth;
	Room* pSouth;

	//private:
	string rName;
	string rDesc;
};

void Room::setRoomPokemon(Pokemon* poke)
{
	RoomPokeInventory.push_back(poke);
}


void Room::getRoomPokeInventory()
{
	vector<Pokemon*>::const_iterator iter;
	if (RoomPokeInventory.size() != 0)
	{
		cout << "Pokemon in Room:" << endl;
		for (iter = RoomPokeInventory.begin(); iter != RoomPokeInventory.end(); ++iter)
		{
			cout << (*iter)->m_Name << endl;
		}
	}
	else
		cout << "\nNo Pokemon in room! :'( \n";
}

void Room::getRoomTrainer()
{

}

Room::Room(string n, string desc)
{
	rName = n;
	rDesc = desc;
}


void Room::pRoomName()
{
	cout << rName << endl;

}

void Room::pRoomDesc()
{
	cout << rDesc << endl;
	getRoomPokeInventory();
}

class Map
{
public:
	Map();
	~Map();

	Room* mStart = 0;
	Room* GymLeader_1_Start = 0;
	Room* GymLeader_2_Start = 0;
	Room* GymLeader_3_Start = 0;
	Room* GymLeader_4_Start = 0;
	Room* Champion_Start = 0;
};

Map::~Map()
{
	delete mStart->pNorth;
	delete mStart->pEast;
	delete mStart->pSouth;
	delete mStart->pWest;
}

Map::Map()
{
	vector<Pokemon*> MapPoke = createPokemon();

	Room* PokeLab = new Room("Professor's Lab", "Where new trainers obtain their first pokemon!\n");
	mStart = PokeLab;
	Room* T1 = new Room("Ikena", "Small peaceful town where hero's are born\n");
	GymLeader_3_Start = T1;
	//Room* PokeCenter = new Room("Pokemon Center", "Where Pokemon are fully recovered!\n");
	//Room* PokeMart = new Room("Pokemon Mart", "A place to stock up for your journey\n");

	Room* R1 = new Room("Route 1", "Where you make your first step into your Pokemon Journey!\n");
	Room* R2 = new Room("Route 2", "\n");

	Room* T2 = new Room("Oak Pass", "Town surrounded by trees and forest Pokemon\n");
	GymLeader_1_Start = T2;
	//Room* PokeCenter1 = new Room("Pokemon Center", "Where Pokemon are fully recovered!\n");
	//Room* PokeMart1 = new Room("Pokemon Mart", "A place to stock up for your journey\n");

	Room* R3 = new Room("Route 3", "\n");
	Room* R4 = new Room("Route 4", "Tunnel\n");


	Room* T3 = new Room("New Nucleon", "Founded after Nucleon incident\n");
	GymLeader_2_Start = T3;
	//Room* PokeCenter2 = new Room("Pokemon Center", "Where Pokemon are fully recovered!\n");
	//Room* PokeMart2 = new Room("Pokemon Mart", "A place to stock up for your journey\n");


	Room* R5 = new Room("Route 5", "\n");

	//Travels through Ikena

	Room* R6 = new Room("Route 6", "\n");

	Room* T4 = new Room("Dracoton", "Home of Dragons and Dragon Masters\n");
	GymLeader_4_Start = T4;
	//Room* PokeCenter3 = new Room("Pokemon Center", "Where Pokemon are fully recovered!\n");
	//Room* PokeMart3 = new Room("Pokemon Mart", "A place to stock up for your journey\n");

	Room* R7 = new Room("Route 7", "\n");

	Room* Victory = new Room("Victory Road", "Expert trainers and future Champions all travel through here\n");

	Room* Champion = new Room("Championships", "Where you find out if your the best!\n");
	Champion_Start = Champion;

	Room* TheEnd = new Room("The End", "Decide where you wish to stay\n");

	//Inserts Pokemon into Rooms
	R1->setRoomPokemon(MapPoke[3]);

	R2->setRoomPokemon(MapPoke[15]);
	R2->setRoomPokemon(MapPoke[12]);

	R3->setRoomPokemon(MapPoke[9]);
	R3->setRoomPokemon(MapPoke[11]);

	R4->setRoomPokemon(MapPoke[10]);

	R5->setRoomPokemon(MapPoke[7]);

	R6->setRoomPokemon(MapPoke[14]);

	R7->setRoomPokemon(MapPoke[4]);
	R7->setRoomPokemon(MapPoke[13]);

	Victory->setRoomPokemon(MapPoke[8]);
	Victory->setRoomPokemon(MapPoke[6]);
	Victory->setRoomPokemon(MapPoke[17]);

	TheEnd->setRoomPokemon(MapPoke[19]);

	//Direction Key
	//Player Start
	PokeLab->pNorth = T1;

	T1->pNorth = R5;		//only if player has 2 badges
	T1->pEast = R6;
	T1->pSouth = PokeLab;
	T1->pWest = R1;

	R1->pEast = T1;
	R1->pWest = R2;

	R2->pEast = R1;
	R2->pWest = T2;

	T2->pNorth = T3;	//only if player obtains 3 badges
	T2->pEast = R3;
	T2->pSouth = R2;

	R3->pNorth = R4;
	R3->pWest = T2;

	R4->pNorth = T3;
	R4->pSouth = R3;

	T3->pEast = R5;
	T3->pSouth = R4;
	T3->pWest = T2;		//only if player obtains 3 badges

	R5->pWest = T3;
	R5->pEast = T4;		//only if player obtains 4 badges
	R5->pSouth = T1;

	R6->pNorth = T4;
	R6->pWest = T1;

	T4->pEast = R7;
	T4->pSouth = R6;
	T4->pWest = R5;

	R7->pNorth = Victory;		//only if Player obtains 4 badges
	R7->pWest = T4;

	Victory->pNorth = Champion;
	Victory->pSouth = R7;

	Champion->pNorth = TheEnd;
	Champion->pSouth = Victory;

	//Last Room
	TheEnd->pSouth = Champion;

};