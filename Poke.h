#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

class Pokemon			//Class Definition -- defines a new type, Pokemon
{
public:
	Pokemon(const string& name = "");
	~Pokemon();
	string m_Name;	//data member name
	string m_Type;	//data member type
	int m_Speed = 0;	//data member speed
	int BaseHealth = 0;
	int m_Health = 0;	//data member health
	int level = 0;		//data member level
	int id_Number = 0;
	int RanNum();		//generates random num to decide opponent move
	class Move
	{
	public:
		//Move();
		//~Move();
		//void AddMove();
		//void RemoveMove();
		//void Clear();
		string move_Name;
		string move_Type;
		int move_power = 0;
	};
	vector<Move> moves;
	vector<Move>::const_iterator iter;
	void Greet();	//member function prototype


};

Pokemon::Pokemon(const string& name)
{
	m_Name = name;
}
Pokemon::~Pokemon()
{}

void Pokemon::Greet()	//member function definition
{
	cout << "Hi, I'm " << m_Name << endl;
	cout << "My speed is " << m_Speed << ".\n";
	cout << "My moves are:\n";
	for (iter = moves.begin(); iter != moves.end(); ++iter)
	{
		if (iter != moves.end() - 1)
		{
			cout << (*iter).move_Name << " - ";
		}
		else
		{
			cout << (*iter).move_Name << endl;
		}

	}
	cout << "\n\n";
}

int Pokemon::RanNum()
{
	return rand() % 4 + 1;
}

vector<Pokemon*> createPokemon()
{
	Pokemon::Move Tackle;
	Tackle.move_Name = "TACKLE";
	Tackle.move_Type = "normal";
	Tackle.move_power = 5;

	Pokemon::Move QuickAttack;
	QuickAttack.move_Name = "QUICKATTACK";
	QuickAttack.move_Type = "normal";
	QuickAttack.move_power = 5;

	Pokemon::Move Growl;
	Growl.move_Name = "GROWL";
	Growl.move_Type = "normal";
	Growl.move_power = 0;

	Pokemon::Move Leer;
	Leer.move_Name = "LEER";
	Leer.move_Type = "Normal";
	Leer.move_power = 0;

	//Fire Type Moves
	Pokemon::Move Ember;
	Ember.move_Name = "EMBER";
	Ember.move_Type = "fire";
	Ember.move_power = 7;

	Pokemon::Move FireFang;
	FireFang.move_Name = "FIREFANG";
	FireFang.move_Type = "fire";
	FireFang.move_power = 8;

	Pokemon::Move Flamethrower;
	Flamethrower.move_Name = "FLAMETHROWER";
	Flamethrower.move_Type = "fire";
	Flamethrower.move_power = 10;

	Pokemon::Move FireBlitz;
	FireBlitz.move_Name = "FIREBLITZ";
	FireBlitz.move_Type = "fire";
	FireBlitz.move_power = 12;

	Pokemon::Move FlameWheel;
	FlameWheel.move_Name = "FLAMEWHEEL";
	FlameWheel.move_Type = "fire";
	FlameWheel.move_power = 8;

	//Water Type Moves
	Pokemon::Move WaterGun;
	WaterGun.move_Name = "WATERGUN";
	WaterGun.move_Type = "water";
	WaterGun.move_power = 6;

	Pokemon::Move WaterPulse;
	WaterPulse.move_Name = "WATERPULSE";
	WaterPulse.move_Type = "water";
	WaterPulse.move_power = 7;

	Pokemon::Move AquaTail;
	AquaTail.move_Name = "AQUATAIL";
	AquaTail.move_Type = "water";
	AquaTail.move_power = 8;

	Pokemon::Move HydroPump;
	HydroPump.move_Name = "HYDROPUMP";
	HydroPump.move_Type = "water";
	HydroPump.move_power = 12;

	Pokemon::Move Surf;
	Surf.move_Name = "SURF";
	Surf.move_Type = "water";
	Surf.move_power = 10;

	Pokemon::Move Splash;
	WaterGun.move_Name = "SPLASH";
	WaterGun.move_Type = "water";
	WaterGun.move_power = 0;

	//Grass Type Moves
	Pokemon::Move VineWhip;
	VineWhip.move_Name = "VINEWHIP";
	VineWhip.move_Type = "grass";
	VineWhip.move_power = 7;

	Pokemon::Move RazerLeaf;
	RazerLeaf.move_Name = "RAZERLEAF";
	RazerLeaf.move_Type = "grass";
	RazerLeaf.move_power = 10;

	Pokemon::Move SeedBomb;
	SeedBomb.move_Name = "SEEDBOMB";
	SeedBomb.move_Type = "grass";
	SeedBomb.move_power = 12;

	Pokemon::Move PetalBlizzard;
	PetalBlizzard.move_Name = "PETALBLIZZARD";
	PetalBlizzard.move_Type = "grass";
	PetalBlizzard.move_power = 14;

	Pokemon::Move Synthesis;
	Synthesis.move_Name = "SYNTHESIS";
	Synthesis.move_Type = "grass";
	Synthesis.move_power = 5;

	Pokemon::Move SolarBeam;
	SolarBeam.move_Name = "SOLARBEAM";
	SolarBeam.move_Type = "grass";
	SolarBeam.move_power = 12;

	//bug Type Moves
	Pokemon::Move StringShot;
	StringShot.move_Name = "STRINGSHOT";
	StringShot.move_Type = "bug";
	StringShot.move_power = 2;

	Pokemon::Move BugBuzz;
	BugBuzz.move_Name = "BUGBUZZ";
	BugBuzz.move_Type = "bug";
	BugBuzz.move_power = 2;

	Pokemon::Move FuryCutter;
	FuryCutter.move_Name = "FURYCUTTER";
	FuryCutter.move_Type = "bug";
	FuryCutter.move_power = 7;

	Pokemon::Move Harden;
	Harden.move_Name = "HARDEN";
	Harden.move_Type = "bug";
	Harden.move_power = 2;

	//ground type moves
	Pokemon::Move RockSmash;
	RockSmash.move_Name = "ROCKSMASH";
	RockSmash.move_Type = "ground";
	RockSmash.move_power = 7;

	Pokemon::Move RollOut;
	RollOut.move_Name = "ROLLOUT";
	RollOut.move_Type = "ground";
	RollOut.move_power = 7;

	Pokemon::Move Earthquake;
	Earthquake.move_Name = "EARTHQUAKE";
	Earthquake.move_Type = "ground";
	Earthquake.move_power = 12;

	//flying type moves
	Pokemon::Move Peck;
	Peck.move_Name = "PECK";
	Peck.move_Type = "flying";
	Peck.move_power = 5;

	Pokemon::Move WingAttack;
	WingAttack.move_Name = "WINGATTACK";
	WingAttack.move_Type = "flying";
	WingAttack.move_power = 7;

	Pokemon::Move Gust;
	Gust.move_Name = "GUST";
	Gust.move_Type = "flying";
	Gust.move_power = 7;

	Pokemon::Move Hurricane;
	Hurricane.move_Name = "HURRICANE ";
	Hurricane.move_Type = "flying";
	Hurricane.move_power = 10;

	Pokemon::Move Roost;
	Roost.move_Name = "ROOST";
	Roost.move_Type = "flying";
	Roost.move_power = 5;

	Pokemon::Move Bounce;
	Bounce.move_Name = "BOUNCE";
	Bounce.move_Type = "flying";
	Bounce.move_power = 10;

	//Fighting Type Moves
	Pokemon::Move LowSweep;
	LowSweep.move_Name = "LOWSWEEP";
	LowSweep.move_Type = "fighting";
	LowSweep.move_power = 8;

	Pokemon::Move BulkUp;
	BulkUp.move_Name = "BULKUP";
	BulkUp.move_Type = "fighting";
	BulkUp.move_power = 5;

	Pokemon::Move DynamicPunch;
	DynamicPunch.move_Name = "DYNAMICPUNCH";
	DynamicPunch.move_Type = "fighting";
	DynamicPunch.move_power = 5;

	Pokemon::Move KarateChop;
	KarateChop.move_Name = "KARATECHOP";
	KarateChop.move_Type = "fighting";
	KarateChop.move_power = 5;

	Pokemon::Move Revenge;
	Revenge.move_Name = "REVENGE";
	Revenge.move_Type = "fighting";
	Revenge.move_power = 5;

	//Physic Type Moves
	Pokemon::Move Confusion;
	Confusion.move_Name = "CONFUSION";
	Confusion.move_Type = "Physic";
	Confusion.move_power = 7;

	Pokemon::Move Physic;
	Physic.move_Name = "PHYSIC";
	Physic.move_Type = "Physic";
	Physic.move_power = 8;

	Pokemon::Move Moonblast;
	Moonblast.move_Name = "MOONBLAST";
	Moonblast.move_Type = "Physic";
	Moonblast.move_power = 10;

	Pokemon::Move Moonlight;
	Moonlight.move_Name = "MOONLIGHT";
	Moonlight.move_Type = "Physic";
	Moonlight.move_power = 10;

	Pokemon::Move Sunlight;
	Sunlight.move_Name = "SUNLIGHT";
	Sunlight.move_Type = "Physic";
	Sunlight.move_power = 10;

	//Dark Type Moves
	Pokemon::Move DarkPulse;
	DarkPulse.move_Name = "DARKPULSE";
	DarkPulse.move_Type = "Dark";
	DarkPulse.move_power = 10;

	Pokemon::Move Bite;
	Bite.move_Name = "BITE";
	Bite.move_Type = "Dark";
	Bite.move_power = 8;

	//Electric Type Moves
	Pokemon::Move Spark;
	Spark.move_Name = "SPARK";
	Spark.move_Type = "Electric";
	Spark.move_power = 7;

	Pokemon::Move Thunderbolt;
	Thunderbolt.move_Name = "THUNDERBOLT";
	Thunderbolt.move_Type = "Electric";
	Thunderbolt.move_power = 10;

	Pokemon::Move Thunder;
	Thunder.move_Name = "THUNDER";
	Thunder.move_Type = "Electric";
	Thunder.move_power = 12;

	vector<Pokemon*> vec;

	Pokemon* Null0 = new Pokemon;
	Null0->id_Number = 0;
	Null0->m_Name = "ZERO";
	Null0->m_Type = "Zero";
	Null0->m_Speed = 0;
	Null0->m_Health = 0;
	Null0->moves.insert(Null0->moves.end(), { Tackle, Tackle, Tackle, Tackle });

	Pokemon* Umbreon = new Pokemon;
	Umbreon->id_Number = 1;
	Umbreon->m_Name = "UMBREON";
	Umbreon->m_Type = "dark";
	Umbreon->m_Speed = 9;
	Umbreon->BaseHealth = 75;
	Umbreon->m_Health = 75;
	
	Umbreon->moves.insert(Umbreon->moves.end(), { Moonlight, DarkPulse, Bite, Tackle });

	Pokemon* Espeon = new Pokemon;
	Espeon->id_Number = 2;
	Espeon->m_Name = "ESPEON";
	Espeon->m_Type = "physic";
	Espeon->m_Speed = 7;
	Espeon->BaseHealth = 75;
	Espeon->m_Health = 75;
	Espeon->moves.insert(Espeon->moves.end(), { Sunlight, Confusion, Physic, Moonblast });

	Pokemon* Bulbasaur = new Pokemon;
	Bulbasaur->id_Number = 3;
	Bulbasaur->m_Name = "BULBASAUR";
	Bulbasaur->m_Type = "grass";
	Bulbasaur->m_Speed = 7;
	Bulbasaur->BaseHealth = 40;
	Bulbasaur->m_Health = 40;
	Bulbasaur->moves.insert(Bulbasaur->moves.end(), { Tackle, VineWhip, RazerLeaf, QuickAttack });

	Pokemon* Venusaur = new Pokemon;
	Venusaur->id_Number = 4;
	Venusaur->m_Name = "VENUSAUR";
	Venusaur->m_Type = "grass";
	Venusaur->m_Speed = 7;
	Venusaur->BaseHealth = 80;
	Venusaur->m_Health = 80;
	Venusaur->moves.insert(Venusaur->moves.end(), { PetalBlizzard, SolarBeam, Earthquake, Sunlight });

	Pokemon* Squirtle = new Pokemon;
	Squirtle->id_Number = 5;
	Squirtle->m_Name = "SQUIRTLE";
	Squirtle->m_Type = "water";
	Squirtle->m_Speed = 7;
	Squirtle->BaseHealth = 40;
	Squirtle->m_Health = 40;
	Squirtle->moves.insert(Squirtle->moves.end(), { WaterGun, QuickAttack, WaterPulse, Bite });

	Pokemon* Blastoise = new Pokemon;
	Blastoise->id_Number = 6;
	Blastoise->m_Name = "BLASTOISE";
	Blastoise->m_Type = "water";
	Blastoise->m_Speed = 7;
	Blastoise->m_Health = 80;
	Blastoise->BaseHealth = 80;
	Blastoise->moves.insert(Blastoise->moves.end(), { Bite, HydroPump, Surf, QuickAttack });

	Pokemon* Charmander = new Pokemon;
	Charmander->id_Number = 7;
	Charmander->m_Name = "CHARMANDER";
	Charmander->m_Type = "fire";
	Charmander->m_Speed = 7;
	Charmander->m_Health = 40;
	Charmander->BaseHealth = 40;
	Charmander->moves.insert(Charmander->moves.end(), { Tackle, Ember, FireFang, QuickAttack });

	Pokemon* Charizard = new Pokemon;
	Charizard->id_Number = 8;
	Charizard->m_Name = "CHARIZARD";
	Charizard->m_Type = "fire";
	Charizard->m_Speed = 7;
	Charizard->m_Health = 80;
	Charizard->BaseHealth = 80;
	Charizard->moves.insert(Charizard->moves.end(), { WingAttack, Flamethrower, FireBlitz, QuickAttack });

	Pokemon* Graveler = new Pokemon;
	Graveler->id_Number = 9;
	Graveler->m_Name = "GRAVELER";
	Graveler->m_Type = "ground";
	Graveler->m_Speed = 7;
	Graveler->m_Health = 70;
	Graveler->BaseHealth = 70;
	Graveler->moves.insert(Graveler->moves.end(), { QuickAttack, RockSmash, RollOut, Earthquake });

	Pokemon* Onix = new Pokemon;
	Onix->id_Number = 10;
	Onix->m_Name = "ONIX";
	Onix->m_Type = "ground";
	Onix->m_Speed = 7;
	Onix->m_Health = 75;
	Onix->BaseHealth = 75;
	Onix->moves.insert(Onix->moves.end(), { QuickAttack, RockSmash, RollOut, Earthquake });

	Pokemon* Pikachu = new Pokemon;
	Pikachu->id_Number = 11;
	Pikachu->m_Name = "PIKACHU";
	Pikachu->m_Type = "electric";
	Pikachu->m_Speed = 7;
	Pikachu->m_Health = 75;
	Pikachu->BaseHealth = 75;
	Pikachu->moves.insert(Pikachu->moves.end(), { Spark, Thunderbolt, QuickAttack, Surf });

	Pokemon* Magikarp = new Pokemon;
	Magikarp->id_Number = 12;
	Magikarp->m_Name = "MAGIKARP";
	Magikarp->m_Type = "water";
	Magikarp->m_Speed = 7;
	Magikarp->m_Health = 40;
	Magikarp->BaseHealth = 40;
	Magikarp->moves.insert(Magikarp->moves.end(), { Splash, Tackle, QuickAttack, Growl });

	Pokemon* Gyrados = new Pokemon;
	Gyrados->id_Number = 13;
	Gyrados->m_Name = "GYRADOS";
	Gyrados->m_Type = "water";
	Gyrados->m_Speed = 7;
	Gyrados->m_Health = 80;
	Gyrados->BaseHealth = 80;
	Gyrados->moves.insert(Gyrados->moves.end(), { Bite, HydroPump, Earthquake, Surf });

	Pokemon* Vilepume = new Pokemon;
	Vilepume->id_Number = 14;
	Vilepume->m_Name = "VILEPLUME";
	Vilepume->m_Type = "grass";
	Vilepume->m_Speed = 7;
	Vilepume->m_Health = 80;
	Vilepume->BaseHealth = 80;
	Vilepume->moves.insert(Vilepume->moves.end(), { SeedBomb, RazerLeaf, Earthquake, Physic });

	Pokemon* Pidgey = new Pokemon;
	Pidgey->id_Number = 15;
	Pidgey->m_Name = "PIDGEY";
	Pidgey->m_Type = "flying";
	Pidgey->m_Speed = 7;
	Pidgey->m_Health = 45;
	Pidgey->BaseHealth = 45;
	Pidgey->moves.insert(Pidgey->moves.end(), { Tackle, Peck, QuickAttack, WingAttack });

	Pokemon* Charmeleon = new Pokemon;
	Charmeleon->id_Number = 16;
	Charmeleon->m_Name = "CHARMELEON";
	Charmeleon->m_Type = "fire";
	Charmeleon->m_Speed = 7;
	Charmeleon->m_Health = 65;
	Charmeleon->BaseHealth = 65;
	Charmeleon->moves.insert(Charmeleon->moves.end(), { Flamethrower, QuickAttack, Bite, FlameWheel });

	Pokemon* Salamance = new Pokemon;
	Salamance->id_Number = 17;
	Salamance->m_Name = "SALAMANCE";
	Salamance->m_Type = "dragon";
	Salamance->m_Speed = 7;
	Salamance->m_Health = 90;
	Salamance->BaseHealth = 90;
	Salamance->moves.insert(Salamance->moves.end(), { Flamethrower, WingAttack, Earthquake, Surf });

	Pokemon* Dragonite = new Pokemon;
	Dragonite->id_Number = 18;
	Dragonite->m_Name = "DRAGONITE";
	Dragonite->m_Type = "dragon";
	Dragonite->m_Speed = 7;
	Dragonite->m_Health = 90;
	Dragonite->BaseHealth = 90;
	Dragonite->moves.insert(Dragonite->moves.end(), { Flamethrower, WingAttack, Earthquake, Surf });

	Pokemon* Arceus = new Pokemon;
	Arceus->id_Number = 19;
	Arceus->m_Name = "ARCEUS";
	Arceus->m_Type = "dragon";
	Arceus->m_Speed = 7;
	Arceus->m_Health = 100;
	Arceus->BaseHealth = 100;
	Arceus->moves.insert(Arceus->moves.end(), { Earthquake, DarkPulse, Moonblast, HydroPump });

	vec.insert(vec.end(), { Null0, Umbreon, Espeon, Bulbasaur, Venusaur, Squirtle, Blastoise, Charmander, Charizard, Graveler, Onix, Pikachu, Magikarp, Gyrados, Vilepume, Pidgey, Charmeleon, Salamance, Dragonite, Arceus });


	return vec;
}