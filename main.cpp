#include <iostream>
#include <string>
#include <vector>
#include <ctime>

#include "Player.h"

using namespace std;

string toUpper(string& name)
{
	for (int i = 0; i < name.size(); ++i)
	{
		name[i] = toupper(name[i]);
	}
	return name;
}

string GetName()
{
	cout << "Enter your name\n";
	string PlayerName;
	cin >> PlayerName;
	return PlayerName;
}


void SwapPokemon(Player* Main)
{
	bool flag = false;

	string pokeSwap;
	string swap1 = "";
	string pokeSwap2;
	string swap2 = "";
	int a = 0;
	int b = 0;
	int PokeIntSize = Main->pokeInventory.size();
	bool validPokemon = false;
	bool validPokemon2 = false;

	while (swap1 == "")
	{
		cout << "Heres your Pokemon. Who would you like to trade positions with?\n";
		Main->getPokeInventory();
		cout << endl;


		cin >> pokeSwap;
		toUpper(pokeSwap);

		//checks if pokemon name is in inventory 
		for (int i = 0; i <= Main->pokeInventory.size() - 1; ++i)
		{
			if ((Main->pokeInventory[i]->m_Name == pokeSwap))
			{
				validPokemon = true;
				a = i;
				break;
			}

			else if (i >= 3 && PokeIntSize >= i)
			{
				if ((Main->pokeInventory[i - 1]->m_Name == pokeSwap))
				{
					validPokemon = true;
					a = i - 1;
					break;
				}
			}
		}

		if (validPokemon == true)
		{
			swap1 = pokeSwap;
			cout << "its working.\n";
		}

		else
		{
			cout << "Invalid Pokemon name " << pokeSwap << " .\n";
			cout << "Must type in exact name of pokemon!\n";
		}
	}
	
	if (validPokemon == true)
	{
		while (swap2 == "")
		{
			cout << "\nWho would you like to swap " << pokeSwap << " with?\n\n";
			cin >> pokeSwap2;
			toUpper(pokeSwap2);

			for (int i = 0; i <= Main->pokeInventory.size() - 1; ++i)
			{
				if ((Main->pokeInventory[i]->m_Name == pokeSwap2))
				{
					validPokemon2 = true;
					swap2 = pokeSwap2;
					b = i;
					break;
				}

				else if (i >= 3 && PokeIntSize >= i)
				{
					if ((Main->pokeInventory[i - 1]->m_Name == pokeSwap))
					{
						validPokemon2 = true;
						b = i - 1;
						break;
					}
				}
			}

			if (validPokemon2 == false)
			{
				cout << "Invalid Pokemon name " << pokeSwap2 << " .\n";
				cout << "Must type in exact name of pokemon!\n";
			}
		}	
	}

	if (validPokemon && validPokemon2 == true)
	{		
		cout << "You are swapping: " << swap1 << " and " << swap2 << " .\n\n";
		swap(Main->pokeInventory[a], Main->pokeInventory[b]);
	}	//end of swap case
}
void TrainerBattle(Player* Main, CompPlayer* Opponent)
{
	string attackmove;
	int option;
	bool flag = false;
	string menuChoice = "";
	string answer;

	cout << Main->GetName() << " vs " << Opponent->GetName() << "\n\n";
	cout << "You sent out " << Main->pokeInventory[0]->m_Name << endl;
	cout << Opponent->GetName() << " sent out " << Opponent->pokeInventory[0]->m_Name << endl;

	int turn = 0, die = 0;

	while (true)
	{
		cout << "Your " << Main->pokeInventory[0]->m_Name << "'s" << " health is at: " << Main->pokeInventory[0]->m_Health << endl;
		cout << "The opponents " << Opponent->pokeInventory[0]->m_Name << "'s" << " health is at: " << Opponent->pokeInventory[0]->m_Health << "\n\n";

		if (turn == 0)
		{
			if (Main->pokeInventory[0]->m_Health <= 0 || Opponent->pokeInventory[0]->m_Health <= 0)
				break;
			cout << "Your moves.\n";
			for (int i = 0; i <= Main->pokeInventory[0]->moves.size() - 1; ++i)
			{
				cout << Main->pokeInventory[0]->moves[i].move_Name << " -- ";
			}
			cout << "\n\nEnter your move.\n";
			cin >> attackmove;
			toUpper(attackmove);

			Pokemon::Move test;
			Pokemon::Move test2;
			test.move_Name = attackmove;

			//check if move name is found in Pokemon MoveSet
			for (int i = 0; i <= 3; ++i)
			{
				if (test.move_Name == Main->pokeInventory[0]->moves[i].move_Name)
				{
					flag = true;
					if (flag == true)
					{
						test2 = Main->pokeInventory[0]->moves[i];
						option = i;
					}
				}
			}
			if (flag == true)
			{
				cout << "You used " << test2.move_Name << " option: " << option << endl;
				//special condition for moves with HEALTH restoring 
				if (test2.move_Name == "MOONLIGHT" || test2.move_Name == "SUNLIGHT")
				{
					if (Main->pokeInventory[0]->m_Health >= Main->pokeInventory[0]->BaseHealth - 10)
					{
						cout << "Nothing happened\n";
						turn = 1;
					}
					else
					{
						Main->pokeInventory[0]->m_Health += Main->pokeInventory[0]->moves[0].move_power;
						cout << "Health Restored\n";
						cout << Main->pokeInventory[0]->m_Health << endl;
						turn = 1;
					}
				}
				else
				{
					cout << "The opponents " << Opponent->pokeInventory[0]->m_Name << " took " << test2.move_power << " damage\n";
					Opponent->pokeInventory[0]->m_Health -= test2.move_power;
					turn = 1;
				}

			}
			else
			{
				cout << attackmove << " is an invalid move.\n";
			}

			if (Opponent->pokeInventory[0]->m_Health <= 0)
			{
				swap(Opponent->pokeInventory[0], Opponent->pokeInventory[1]);
				cout << "\n" << Opponent->GetName() << " sent out " << Opponent->pokeInventory[0]->m_Name << "\n\n";
			}
			if (Opponent->pokeInventory.size() >= 3 && Opponent->pokeInventory[0]->m_Health <= 0 && Opponent->pokeInventory[1]->m_Health <= 0)
			{
				swap(Opponent->pokeInventory[0], Opponent->pokeInventory[2]);
				cout << Opponent->GetName() << " sent out " << Opponent->pokeInventory[0]->m_Name << endl;
			}
			if (Opponent->pokeInventory.size() >= 4 && Opponent->pokeInventory[0]->m_Health <= 0 && Opponent->pokeInventory[1]->m_Health <= 0)
			{
				swap(Opponent->pokeInventory[0], Opponent->pokeInventory[3]);
				cout << Opponent->GetName() << " sent out " << Opponent->pokeInventory[0]->m_Name << endl;
			}
		}

		else            //opponent move
		{
			if (Main->pokeInventory[0]->m_Health <= 0 || Opponent->pokeInventory[0]->m_Health <= 0)
				break;

			flag = false;
			die = Opponent->pokeInventory[0]->RanNum();


			cout << Opponent->pokeInventory[0]->m_Name << " Move\n";
			if (die == 1)
			{
				cout << Opponent->pokeInventory[0]->m_Name << " used " << Opponent->pokeInventory[0]->moves[0].move_Name << endl;
				cout << Main->pokeInventory[0]->m_Name << " took " << Opponent->pokeInventory[0]->moves[0].move_power << " damage.\n";
				Main->pokeInventory[0]->m_Health -= Opponent->pokeInventory[0]->moves[0].move_power;

			}
			if (die == 2)
			{
				cout << Opponent->pokeInventory[0]->m_Name << " used " << Opponent->pokeInventory[0]->moves[1].move_Name << endl;
				cout << Main->pokeInventory[0]->m_Name << " took " << Opponent->pokeInventory[0]->moves[1].move_power << " damage.\n";
				Main->pokeInventory[0]->m_Health -= Opponent->pokeInventory[0]->moves[1].move_power;
			}
			if (die == 3)
			{
				cout << Opponent->pokeInventory[0]->m_Name << " used " << Opponent->pokeInventory[0]->moves[2].move_Name << endl;
				cout << Main->pokeInventory[0]->m_Name << " took " << Opponent->pokeInventory[0]->moves[2].move_power << " damage.\n";
				Main->pokeInventory[0]->m_Health -= Opponent->pokeInventory[0]->moves[2].move_power;
			}
			if (die == 4)
			{
				cout << Opponent->pokeInventory[0]->m_Name << " used " << Opponent->pokeInventory[0]->moves[3].move_Name << endl;
				cout << Main->pokeInventory[0]->m_Name << " took " << Opponent->pokeInventory[0]->moves[3].move_power << " damage.\n";
				Main->pokeInventory[0]->m_Health -= Opponent->pokeInventory[0]->moves[3].move_power;
			}

			if (Main->pokeInventory[0]->m_Health <= 0)
			{
				cout << Main->pokeInventory[0]->m_Name << " fainted.\n";
				cout << "Would you like to switch Pokemon?\n";
				cin >> answer;
				toUpper(answer);
				if (answer == "YES" || answer == "Y")
				{
					SwapPokemon(Main);
				}
			}
			turn = 0;

		}

	}
	if (Main->pokeInventory[0]->m_Health <= 0)
	{
		cout << Main->pokeInventory[0]->m_Name << " fainted.\n";
	}
	if (Opponent->pokeInventory[0]->m_Health <= 0)
	{
		cout << Opponent->GetName() << " defeated.\n";
		cout << "Congratulations! You defeated me. Please take this badge to honor your victory.\n";
		Opponent->Defeated = true;
		Main->BadgeCase.push_back(Opponent->BadgeCase[0]);
	}
}

int main()
{
	vector<Pokemon*> mainPokemon = createPokemon();
	vector<Pokemon*> GymPokemon = createPokemon();
	
	Map GameMap;
	string direction = "";
	string input = "";
	int choice = 0;
	bool BadDirection = false;
	
	cout << "Game Guide:\n";
	cout << "Tip: Set console as full screen for best experience.\n";
	cout << "You can move by typing 'go' followed by the direction (north/south/east/west)\n";
	cout << "You complete an action by typing 'action; or 'a'. this will display the options you can use\n\n\n";


	cout << "One night at your house you hear a storm. Your cats are freaking out and you see lightning dancing outside your windows.\n";
	cout << "While you're praying the tarp on your roof holds up, a strike of lightning rips through your home. You find yourself blinded by intense white light.\n";
	cout << "The last thing you hear is the roar of thunder, briefly making you believe the voice of God was shouting upon you. You black out...\n\n";

	cout << "Professor Acacia, traveling through what locals now call Old Nucleon,\n";
	cout << "is mapping the now abandoned forest while observing Pokemon in the area.\n";
	cout << "While observing a newly hatched Charmander, the sky is overtaken with clouds and it starts thundering and lightning.\n";
	cout << "Without warning, there is a flash of light and the storm dissapates as quickly as it appeared.\n";
	cout << "Briefly blinded, the Professor blinks a few times and suddenly gasps.\n";
	cout << "Lying a few feet in front of her is a young adult, unconcious and barely breathing.\n\n";

	cout << "You wake up in a comforatable bed, disoriented and unsure of exactly where you are..\n";
	cout << "The last thing you remember is a bright white light and the sound of thunder.\n";
	cout << "You hear a knock on the door, and the professor comes in.\n\n";

	cout << "Professsor Aracia: I'm glad your finally awake!\n";
	cout << "You've been unconsious for so long I was worried I'd have to transport you in a pokeball to the hospital! \n";
	cout << "Can I ask what your name is?\n\n";

	Player* pMainPlayer = new Player(GetName());

	cout << "\n\nOkay, " << pMainPlayer->GetName() << ", nice to meet you. Do you remember what happened?\n";
	cout << "You say no, and explain all you remember was the light and thunder.\n";
	cout << "Suddenly, from under your bed are two quick flashes of red light. Two pokemon appear in front of you.\n";

	cout << "Professor: Oh wow are these your Pokemon? They look very well taken care of.\n";
	cout << "You look at them and although you can't remember, you feel as though you've known these two for a long time.\n";
	cout << "You look under your bed where they had appeared. There are also two pokeballs with a note.\n";
	cout << "The note reads: These two have been by your side for many years. Therefore it only seemed right they make this journey with you.\n";
	cout << "Your goal is to become the best. How you accomplish that is up to you.\n";
	cout << "You will find me when you have acheived all you can in this region.\n";
	cout << "Welcome to the world of Pokemon!\n\n";

	cout << "You show the professor the note.\n";
	cout << " Professor: To become the very best.. It's quite a mystery how you appeared, but it seems as though someone has a plan for you..\n";
	cout << "To become the very best in this region I suppose could mean becoming the Champion..\n";
	cout << "Its a long road, but rewarding and you are sure to have many different encounters while working towards your goal.\n";
	cout << "You have to defeat the 4 gyms in this region known as 'Arcadia'. Only then can you challenge the region champion.\n";
	cout << "It seems you already have a good start with those two by your side.\n";
	cout << "This region is full of amazing Pokemon so go explore and get stronger!\n";
	cout << "I can't wait to see how your story unfolds!\n\n";


	//Creating Gym Leaders
	CompPlayer* GymLeader1 = new CompPlayer("Mrs. Mcmann");
	GymLeader1->pGymLoc1;
	GymLeader1->pokeInventory.insert(GymLeader1->pokeInventory.end(), { GymPokemon[3], GymPokemon[14] });
	GymLeader1->BadgeCase.push_back("Grass Badge");

	CompPlayer* GymLeader2 = new CompPlayer("Minofo");
	GymLeader2->pGymLoc2;
	GymLeader2->pokeInventory.insert(GymLeader2->pokeInventory.end(), { GymPokemon[5], GymPokemon[9] });
	GymLeader2->BadgeCase.push_back("Water Badge");

	CompPlayer* GymLeader3 = new CompPlayer("Golden");
	GymLeader3->pGymLoc3;
	GymLeader3->pokeInventory.insert(GymLeader3->pokeInventory.end(), { GymPokemon[10], GymPokemon[16] });
	GymLeader3->BadgeCase.push_back("Rock Badge");

	CompPlayer* GymLeader4 = new CompPlayer("Wiggins");
	GymLeader4->pGymLoc4;
	GymLeader4->pokeInventory.insert(GymLeader4->pokeInventory.end(), { GymPokemon[13], GymPokemon[17] });
	GymLeader4->BadgeCase.push_back("Dragon Badge");

	CompPlayer* Arcadia_Champion = new CompPlayer("Adam");
	Arcadia_Champion->pChampLoc1;
	Arcadia_Champion->pokeInventory.insert(Arcadia_Champion->pokeInventory.end(), { GymPokemon[4], GymPokemon[8], GymPokemon[6], GymPokemon[18] });
	Arcadia_Champion->BadgeCase.push_back("Champion Badge");

	Pokemon* Player_Poke_3 = 0;
	Pokemon* Player_Poke_4 = 0;
	Pokemon* Player_Poke_5 = 0;
	Pokemon* Player_Poke_6 = 0;

	pMainPlayer->pLoc->pRoomName();
	pMainPlayer->pLoc->pRoomDesc();

	pMainPlayer->pokeInventory.push_back(mainPokemon[1]);
	pMainPlayer->pokeInventory.push_back(mainPokemon[2]);

	do
	{
		cout << "\nMove or action? (GO || G || Action || A)\n";
		cin >> input;
		toUpper(input);

		//Move Player 
		if (input == "GO" || input == "G")
		{
			cout << "\nWhat direction would you like to move? (North || East || South || West || Quit)\n";
			cin >> direction;
			toUpper(direction);

			if (direction == "NORTH")
			{
				choice = 1;
			}
			else if (direction == "EAST")
			{
				choice = 2;
			}
			else if (direction == "SOUTH")
			{
				choice = 3;
			}
			else if (direction == "WEST")
			{
				choice = 4;
			}
			else if (direction == "QUIT")
			{
				choice = 5;
				cout << "Goodbye\n";
				break;
			}
			else
			{
				choice = 6;
			}

			switch (choice)
			{
			case 1:
				//Player Moving North
				if (pMainPlayer->pLoc->pNorth == nullptr)
				{
					cout << "\nError, you cant go this way.\n\n";
					break;
				}

				if (pMainPlayer->pLoc->rName == "Oak Pass" && pMainPlayer->pLoc->pNorth->rName == "New Nucleon")
				{
					if (pMainPlayer->BadgeCase.size() < 2)
					{
						cout << "You need to obtain 2 badges before this way unlocks!\n";
						cout << "You currently have " << pMainPlayer->BadgeCase.size() << " total badges.\n";
						break;
					}
					else
					{
						pMainPlayer->pLoc = pMainPlayer->pLoc->pNorth;

						cout << endl;

						pMainPlayer->pLoc->pRoomName();
						pMainPlayer->pLoc->pRoomDesc();
						break;
					}
				}

				else if (pMainPlayer->pLoc->pNorth->rName == "Route 5")
				{
					if (pMainPlayer->BadgeCase.size() < 1)
					{
						cout << "You need to obtain 1 badges before this way unlocks!\n";
						cout << "You currently have " << pMainPlayer->BadgeCase.size() << " total badges.\n";
						break;
					}
					else
					{
						pMainPlayer->pLoc = pMainPlayer->pLoc->pNorth;

						cout << endl;

						pMainPlayer->pLoc->pRoomName();
						pMainPlayer->pLoc->pRoomDesc();
						break;
					}
				}

				else if (pMainPlayer->pLoc->pNorth->rName == "The End" && Arcadia_Champion->Defeated == false)
				{
						cout << "Your not ready to go here yet. You must become the Champion of the region to proceed.\n";
						break;			
				}

				else
				{
					pMainPlayer->pLoc = pMainPlayer->pLoc->pNorth;

					cout << endl;

					pMainPlayer->pLoc->pRoomName();
					pMainPlayer->pLoc->pRoomDesc();
					break;
				}
			case 2:
				//Player Moving EAST
				if (pMainPlayer->pLoc->pEast == nullptr)
				{
					cout << "Error, you cant go this way.\n";
					break;
				}
				
				if (pMainPlayer->pLoc->pEast->rName == "Route 6")
				{
					if (pMainPlayer->BadgeCase.size() <= 2)
					{
						cout << "You need to obtain 3 badges before this way unlocks!\n";
						cout << "You currently have " << pMainPlayer->BadgeCase.size() << " total badges.\n";
						break;
					}
					else
					{
						pMainPlayer->pLoc = pMainPlayer->pLoc->pEast;

						cout << endl;

						pMainPlayer->pLoc->pRoomName();
						pMainPlayer->pLoc->pRoomDesc();
						break;
					}			
					
				}

				else if (pMainPlayer->pLoc->pEast->rName == "Dracoton")
				{
					if (pMainPlayer->BadgeCase.size() <= 3)
					{
						cout << "You need to obtain 4 badges before this way unlocks!\n";
						cout << "You currently have " << pMainPlayer->BadgeCase.size() << " total badges.\n";
						break;
					}
					else
					{
						pMainPlayer->pLoc = pMainPlayer->pLoc->pEast;

						cout << endl;

						pMainPlayer->pLoc->pRoomName();
						pMainPlayer->pLoc->pRoomDesc();
						break;
					}

				}

				else
				{
					pMainPlayer->pLoc = pMainPlayer->pLoc->pEast;

					cout << endl;

					pMainPlayer->pLoc->pRoomName();
					pMainPlayer->pLoc->pRoomDesc();
					break;
				}
			case 3:
				//Player Moving South
				if (pMainPlayer->pLoc->pSouth == nullptr)
				{
					cout << "Error, you cant go this way.\n";
					break;
				}
				else
				{
					pMainPlayer->pLoc = pMainPlayer->pLoc->pSouth;

					cout << endl;

					pMainPlayer->pLoc->pRoomName();
					pMainPlayer->pLoc->pRoomDesc();
					break;
				}
			case 4:
				//Player Moving West
				if (pMainPlayer->pLoc->pWest == nullptr)
				{
					cout << "Error, you cant go this way.\n";
					break;
				}
				else
				{
					pMainPlayer->pLoc = pMainPlayer->pLoc->pWest;

					cout << endl;

					pMainPlayer->pLoc->pRoomName();
					pMainPlayer->pLoc->pRoomDesc();
					break;
				}
			case 5:
				//Player End Game
				cout << "Goodbye!\n";
				break;

			case 6:
				//Player Error
				cout << "\nSorry, " << direction << " is invalid.\n";
				break;
			}

		}

		//Player Action
		else if (input == "ACTION" || input == "A")
		{
			cout << "\nWhat would you like to do?\n";
			cout << "(Battle (battle/b) || PokeInventory (pokeinventory/pi) || Menu (menu/m)\n\n";
			string Play;
			int actionChoice = 0;

			cin >> Play;
			toUpper(Play);

			if (Play == "BATTLE" || Play == "B")
			{
				actionChoice = 1;
			}
			else if (Play == "POKEINVENTORY" || Play == "PI")
			{
				actionChoice = 2;
			}
			else if (Play == "MENU" || Play == "M")
			{
				actionChoice = 3;
			}
			else
			{
				actionChoice = 4;
			}

			string catchPoke;
			Pokemon* Player_Poke_1 = pMainPlayer->pokeInventory[0];
			Pokemon* Player_Poke_2 = pMainPlayer->pokeInventory[1];

			if (pMainPlayer->pokeInventory.size() >= 3)
			{
				Player_Poke_3 = pMainPlayer->pokeInventory[2];
			}
			if (pMainPlayer->pokeInventory.size() >= 4)
			{
				Player_Poke_4 = pMainPlayer->pokeInventory[3];
			}
			if (pMainPlayer->pokeInventory.size() >= 5)
			{
				Player_Poke_5 = pMainPlayer->pokeInventory[4];
			}
			if (pMainPlayer->pokeInventory.size() >= 6)
			{
				Player_Poke_6 = pMainPlayer->pokeInventory[5];
			}

			Pokemon one;
			string attackmove;
			int option;
			bool flag = false;
			string menuChoice = "";
			int menuOption;
			string answer;

			switch (actionChoice)
			{
			case 1:		//ActionChoice == Battle
				if (pMainPlayer->pLoc->RoomPokeInventory.size() != 0)
				{
					Pokemon* one = pMainPlayer->pLoc->RoomPokeInventory[0];
					cout << "A wild " << one->m_Name << " attacked!\n";
					int turn = 0, die = 0;
					while (true)
					{
						cout << "Your " << Player_Poke_1->m_Name << "'s" << " health is at: " << Player_Poke_1->m_Health << endl;
						cout << "The wild " << one->m_Name << "'s" << " health is at: " << one->m_Health << "\n\n";

						if (turn == 0)
						{
							if (Player_Poke_1->m_Health <= 0 || one->m_Health <= 0)
								break;
							cout << "Your moves.\n";
							for (int i = 0; i <= Player_Poke_1->moves.size() - 1; ++i)
							{
								cout << Player_Poke_1->moves[i].move_Name << " -- ";
							}
							cout << "\n\nEnter your move.\n";
							cin >> attackmove;
							toUpper(attackmove);

							Pokemon::Move test;
							Pokemon::Move test2;
							test.move_Name = attackmove;

							//check if move name is found in Pokemon MoveSet
							for (int i = 0; i <= 3; ++i)
							{								
								if (test.move_Name == Player_Poke_1->moves[i].move_Name)
								{
									flag = true;
									if (flag == true)
									{
										test2 = Player_Poke_1->moves[i];
										option = i;
									}
								}
							}
							if (flag == true)
							{
								cout << "You used " << test2.move_Name << " option: " << option << endl;
								if (test2.move_Name == "MOONLIGHT" || test2.move_Name == "SUNLIGHT")
								{
									if (Player_Poke_1->m_Health >= 61)
									{
										cout << "Nothing happened\n";
										turn = 1;
									}
									else
									{
										Player_Poke_1->m_Health += Player_Poke_1->moves[0].move_power;
										cout << "Health Restored\n";
										cout << Player_Poke_1->m_Health << endl;
										turn = 1;
									}
								}
								else
								{
									cout << "The wild " << one->m_Name << " took " << test2.move_power << " damage\n";
									one->m_Health -= test2.move_power;
									turn = 1;
								}

							}
							else
							{
								cout << attackmove << " is an invalid move.\n";
							}

						}

						else            //opponent move
						{
							if (Player_Poke_1->m_Health <= 0 || one->m_Health <= 0)
								break;

							die = one->RanNum();

							flag = false;
							cout << one->m_Name << " Move\n";
							if (die == 1)
							{
								cout << one->m_Name << " used " << one->moves[0].move_Name << endl;
								cout << Player_Poke_1->m_Name << " took " << one->moves[0].move_power << " damage.\n";
								Player_Poke_1->m_Health -= one->moves[0].move_power;

							}
							if (die == 2)
							{
								cout << one->m_Name << " used " << one->moves[1].move_Name << endl;
								cout << Player_Poke_1->m_Name << " took " << one->moves[1].move_power << " damage.\n";
								Player_Poke_1->m_Health -= one->moves[1].move_power;
							}
							if (die == 3)
							{
								cout << one->m_Name << " used " << one->moves[2].move_Name << endl;
								cout << Player_Poke_1->m_Name << " took " << one->moves[2].move_power << " damage.\n";
								Player_Poke_1->m_Health -= one->moves[2].move_power;
							}
							if (die == 4)
							{
								cout << one->m_Name << " used " << one->moves[3].move_Name << endl;
								cout << Player_Poke_1->m_Name << " took " << one->moves[3].move_power << " damage.\n";
								Player_Poke_1->m_Health -= one->moves[3].move_power;
							}

							//if defeats player pokemon ask if you want to switch to another in party
							if (Player_Poke_1->m_Health <= 0)
							{
								cout << Player_Poke_1->m_Name << " fainted.\n";
								cout << "Would you like to switch Pokemon? (YES/NO)\n";
								cin >> answer;
								toUpper(answer);
								if (answer == "YES" || answer == "Y")
								{
									SwapPokemon(pMainPlayer);
									Player_Poke_1 = pMainPlayer->pokeInventory[0];
								}
							}
							turn = 0;
						}

						if (Player_Poke_1->m_Health <= 0)
						{
							cout << Player_Poke_1->m_Name << " fainted.\n";
						}

						if (one->m_Health <= 0)
						{
							string pokecatch = "INVALID";
							string PokeRelease = "";
							bool validPokemon = false;
							int PokeInvSize = pMainPlayer->pokeInventory.size();
							Pokemon* pRelease = 0;

							cout << one->m_Name << " fainted.\n";

							while (pokecatch == "INVALID")
							{
								cout << "Would you like to catch " << one->m_Name << "? -- (yes or no)\n";
								cin >> pokecatch;
								toUpper(pokecatch);


								if (pokecatch == "YES" || pokecatch == "Y")
								{
									//check if Player PokeInventory has 6 pokemon
									//if yes than ask player to removes a pokemon from player inventory and inserts removed pokemon in room
									//
									if (PokeInvSize >= 6)
									{
										cout << "\n" << pMainPlayer->GetName() << "'s PokeInventory is full.\n";
										cout << "You can only have 6 Pokemon with you at a time.\n";
										cout << "Would you like to release a Pokemon? -- (yes or no)\n";
										cin >> pokecatch;
										toUpper(pokecatch);
										if (pokecatch == "YES" || pokecatch == "Y")
										{
											pMainPlayer->getPokeInventory();
											while (validPokemon != true)
											{
												cout << "Who would you like to release?\n";
												cin >> PokeRelease;
												toUpper(PokeRelease);
												//checks if pokemon name is in inventory 

												for (int i = 0; i <= 5; ++i)
												{
													if ((pMainPlayer->pokeInventory[i]->m_Name == PokeRelease))
													{
														validPokemon = true;
														pRelease = pMainPlayer->pokeInventory[i];
														break;
													}

													else if (i >= 3 && (PokeInvSize >= i))
													{
														if ((pMainPlayer->pokeInventory[i - 1]->m_Name == PokeRelease))
														{
															validPokemon = true;
															pRelease = pMainPlayer->pokeInventory[i - 1];
															break;
														}
													}
												}	//end for loop

												if (validPokemon == false)
												{
													cout << PokeRelease << " is not a valid Pokemon name.\n";
												}
											}

											if (validPokemon == true)
											{
												cout << "You are releasing: " << pRelease->m_Name << endl;
												//Restores Released pokemon's health back to original value
												pRelease->m_Health = 20;

												pMainPlayer->pLoc->RoomPokeInventory.push_back(pRelease);
												pMainPlayer->pokeInventory.erase(find(pMainPlayer->pokeInventory.begin(), pMainPlayer->pokeInventory.end(), pRelease));

												pMainPlayer->pokeInventory.push_back(one);
												pMainPlayer->pLoc->RoomPokeInventory.erase(find(pMainPlayer->pLoc->RoomPokeInventory.begin(), pMainPlayer->pLoc->RoomPokeInventory.end(), one));
												cout << "You caught " << one->m_Name << "!\n";
											}

										}
									}
									else		//less than 6 in inventory go ahead and add pokemon to inventory
									{
										pMainPlayer->pokeInventory.push_back(one);
										pMainPlayer->pLoc->RoomPokeInventory.erase(find(pMainPlayer->pLoc->RoomPokeInventory.begin(), pMainPlayer->pLoc->RoomPokeInventory.end(), one));
										cout << "You caught " << one->m_Name << "!\n";
									}
								}
								else if (pokecatch == "NO" || pokecatch == "N" || PokeRelease == "NO" || PokeRelease == "N")
								{
									cout << one->m_Name << " ran away!\n";
									pMainPlayer->pLoc->RoomPokeInventory.erase(find(pMainPlayer->pLoc->RoomPokeInventory.begin(), pMainPlayer->pLoc->RoomPokeInventory.end(), one));
								}
								else
								{
									cout << "Invalid input.\n";
									pokecatch = "INVALID";
								}
							}
							


							break;
						}

					}
				}

				else
				{
					Pokemon* one = mainPokemon[0];
					cout << "No pokemon nearby\n";
					break;
				}



			case 2:		//ActionChoice == PokeInventoy/PI
				pMainPlayer->getPokeInventory();

				break;

			case 3:			//ActionChoice == menu
				cout << "\nMenu\n";
				cout << "Heal Pokemon (heal/h)\n";	//case1
				cout << "Check Bag (bag/b)\n";		//case2
				cout << "Swap Pokemon (swap/b)\n"; //case 3
				cout << "Check Gyms (gym/g)\n";	  //case 4

				cout << "\nWhat would you like to do?\n";
				cin >> menuChoice;
				toUpper(menuChoice);

				if (menuChoice == "HEAL" || menuChoice == "H")			//case 1
				{
					menuOption = 1;
				}
				else if (menuChoice == "BAG" || menuChoice == "B")		//case 2
				{
					menuOption = 2;
				}
				else if (menuChoice == "SWAP" || menuChoice == "S")		//case 3
				{
					menuOption = 3;
				}
				else if (menuChoice == "GYM" || menuChoice == "G")		//case 4
				{
					menuOption = 4;
				}
				else
				{
					cout << "Invalid Menu Choice " << menuChoice << endl;
					menuOption = 0;
				}

				switch (menuOption)
				{
				case 1:		//heal
					//if in a town and heals, poke health fully restored

					if (pMainPlayer->pLoc->rName == "Ikena" || pMainPlayer->pLoc->rName == "Oak Pass"
						|| pMainPlayer->pLoc->rName == "New Nucleon" || pMainPlayer->pLoc->rName == "Dracoton" || pMainPlayer->pLoc->rName == "Victory Road")
					{
						//Player_Poke_1->m_Health = mainPokemon[1]->BaseHealth;
						//restores all pokemon in party
						for (int i = 0; i <= mainPokemon.size() - 1; ++i)
						{
							if (Player_Poke_1->m_Name == mainPokemon[i]->m_Name)
							{
								Player_Poke_1->m_Health = mainPokemon[i]->BaseHealth;
							}
							if (Player_Poke_2->m_Name == mainPokemon[i]->m_Name)
							{
								Player_Poke_2->m_Health = mainPokemon[i]->BaseHealth;
							}
							if (Player_Poke_3 != 0 && Player_Poke_3->m_Name == mainPokemon[i]->m_Name)
							{
								Player_Poke_3->m_Health = mainPokemon[i]->BaseHealth;
							}
							if (Player_Poke_4 != 0 && Player_Poke_4->m_Name == mainPokemon[i]->m_Name)
							{
								Player_Poke_4->m_Health = mainPokemon[i]->BaseHealth;
							}
							if (Player_Poke_5 != 0 && Player_Poke_5->m_Name == mainPokemon[i]->m_Name)
							{
								Player_Poke_5->m_Health = mainPokemon[i]->BaseHealth;
							}
							if (Player_Poke_6 != 0 && Player_Poke_6->m_Name == mainPokemon[i]->m_Name)
							{
								Player_Poke_6->m_Health = mainPokemon[i]->BaseHealth;
							}

						}
						cout << "\nAll your Pokemon have been fully restored!\n\n";
					}
					else
					{
						cout << "Can only heal if your in a town!.\n";
					}
					break;

				case 2:		//menuChoice == "bag"
					pMainPlayer->getBadges();
					break;

				case 3:		//swap
					SwapPokemon(pMainPlayer);
					break;

				case 4:			//gym
					//if player is in town with first gym
					answer = "";
					if (pMainPlayer->pLoc->rName == GymLeader1->GymLeader_1_Start->rName)
					{
						if (GymLeader1->Defeated == false)
						{
							cout << "\nHi! My name is " << GymLeader1->GetName() << endl;
							cout << "This is the first Gym new trainers typically challenge.\n";
							cout << "That doesn't mean your about to win easy!\n";

							cout << "Ready to battle?\n";
							cin >> answer;
							toUpper(answer);

							if ((answer == "YES" || answer == "Y") && GymLeader1->Defeated == false)
							{
								TrainerBattle(pMainPlayer, GymLeader1);
							}
						}

						else if (GymLeader1->Defeated == true)
						{
							cout << "You already defeated this gym.\n";
						}

					}
					//if player is in town with second gym
					else if (pMainPlayer->pLoc->rName == GymLeader2->GymLeader_2_Start->rName)
					{
						if (GymLeader2->Defeated == false)
						{
							cout << "The gym leader of this town is: " << GymLeader2->GetName() << endl;

							cout << "\nHi! My name is " << GymLeader2->GetName() << endl;
							cout << "This town may have been remade, but my battle technique is as good as it's ever been!.\n";

							cout << "Ready to battle?\n";
							cin >> answer;
							toUpper(answer);

							if (answer == "YES" || answer == "Y")
							{
								TrainerBattle(pMainPlayer, GymLeader2);
							}
						}
						else if (GymLeader2->Defeated == true)
						{
							cout << "You already defeated this gym.\n";
						}

					}
					//if player is in town with third gym
					else if (pMainPlayer->pLoc->rName == GymLeader3->GymLeader_3_Start->rName)	//can only battle if 2 badges obtained
					{
						if (GymLeader3->Defeated == false)
						{
							//if (pMainPlayer->BadgeCase.size() == 4)
							if (pMainPlayer->BadgeCase.size() >= 2)
							{
								cout << "The gym leader of this town is: " << GymLeader3->GetName() << endl;

								cout << "\nHi! My name is " << GymLeader3->GetName() << endl;
								cout << "This gym starts to really test your skill, which is why I require challengers to have at least 2 badges.\n";
								cout << "Lets see if your worthy of 3\n";

								cout << "Ready to battle?\n";
								cin >> answer;
								toUpper(answer);

								if (answer == "YES" || answer == "Y")
								{
									TrainerBattle(pMainPlayer, GymLeader3);
								}
							}
							else if (pMainPlayer->BadgeCase.size() < 2)
							{
								cout << "You need to have 2 badges to battle this gym!\n";
							}
						}
						else if (GymLeader3->Defeated == true)
						{
							cout << "You already defeated this gym.\n";
						}
					}
					//if player is in town with fourth gym
					else if (pMainPlayer->pLoc->rName == GymLeader4->GymLeader_4_Start->rName)
					{
						if (GymLeader4->Defeated == false)
						{
							cout << "The gym leader of this town is: " << GymLeader4->GetName() << endl;

							cout << "\nHi! My name is " << GymLeader4->GetName() << endl;
							cout << "This is the final Gym for gym challengers.\n";
							cout << "If you beat me you can face the champion. Too bad your journey ends here\n";

							cout << "Ready to battle?\n";
							cin >> answer;
							toUpper(answer);

							if (answer == "YES" || answer == "Y")
							{
								TrainerBattle(pMainPlayer, GymLeader4);
							}
						}
						else if (GymLeader4->Defeated == true)
						{
							cout << "You already defeated this gym.\n";
						}

					}
					//if player is in room with Champion and has obtained all 4 gym badges
					else if (pMainPlayer->pLoc->rName == Arcadia_Champion->Champion_Start->rName)
					{
						if (Arcadia_Champion->Defeated == false)
						{
							if (pMainPlayer->BadgeCase.size() == 4)
							{
								cout << "Arcadia Champion: " << Arcadia_Champion->GetName() << endl;

								cout << "\nHi! My name is " << Arcadia_Champion->GetName() << endl;
								cout << "Are you the strongest trainer in the region?\n";
								cout << "You have to defeat me if you want to prove it!\n";

								cout << "Ready to battle?\n";
								cin >> answer;
								toUpper(answer);

								if (answer == "YES" || answer == "Y")
								{
									TrainerBattle(pMainPlayer, Arcadia_Champion);
								}
							}
							else if (pMainPlayer->BadgeCase.size() < 4)
							{
								cout << "You need to have battled all 4 gyms in the region to face the Champion.\n";
								cout << "You currently only have: " << pMainPlayer->BadgeCase.size() << " badges.\n";
							}
						}
						else if (Arcadia_Champion->Defeated == true)
						{
							cout << "You already are Champion of this region Perhaps a little ways north will one final challenge.\n";
						}
					}
					else
					{
						cout << "No Pokemon Gym in area.\n";
					}

				}	//end of menu switch

				break;

			case 4:
				//Player Error
				cout << "\nSorry, " << Play << " is invalid.\n";
				break;
				
			case 0:
				cout << "Invalid menu option.\n";
				break;
			}

			

		}
		else
		{
			cout << input << " is invalid\n";
		}

		//end the game
		if (pMainPlayer->pLoc->rName == "The End")
		{
			pMainPlayer->pLoc->pRoomName();
			pMainPlayer->pLoc->pRoomDesc();

			if (pMainPlayer->pLoc->RoomPokeInventory.size() != 0)
			{
				cout << "\n\nArceus Voice: I knew you would eventually find your way here.\n";
				cout << "Your potential was clear to me the first time you were in my presence.\n";
				cout << "You have proven your the best Pokemon Trainer in the Arcadia. But are you stronger than the god of this region?\n";
				cout << "Face me to find if you truly are the best.\n\n";
			}		

			if (pMainPlayer->pLoc->RoomPokeInventory.size() == 0)
			{
				cout << "\nYou have defeated all the strongest trainers in Pokemon in this region.\n\n";
				cout << "Do you wish to stay in this world?\n";
				string answer;
				cin >> answer;
				toUpper(answer);
				if (answer == "NO" || answer == "N")
				{
					cout << "Goodbye, may you find as much joy back home.\n";
					direction = "quit";
				}
				else if (answer == "YES" || answer == "Y")
				{
					cout << "Your welcome to stay, type 'quit' to leave.\n";
				}
				else
				{
					cout << "Invalid input\n";
				}
			}	

		}

	} while (direction != "quit");


	system("pause");
	return 0;
}


//Travel the Map until you reach the last room then you have a final battle. if you win the game, you recieve a message "you won" and game ends
//
//Goal :
//12 Rooms :
//	4 Towns
//	6 Routes
//	Championships
//	The End
//
//	Towns :
//Place to Heal Pokemon
//Place to Buy Items
//Place to Battle Gym
//
//Routes
//Contains Wild Pokemon for Player to Battle or Catch
//Contains 1 / 2 Trainers to Battle
//
//Championships
//Place to Battle Champion and become Champion if you win
//
//The End
//One final battle.Final question : do yo wish to stay in the pokeworld or return to your own.If yes, game ends