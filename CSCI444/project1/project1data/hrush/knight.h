//Joust by Hortense Rush
#ifndef KNIGHT_H
#define KNIGHT_H

#include"weapon.h"
#include<string>
using namespace std;

class Knight {
  public:
    bool Charge(string n);
	void Hit();
	Knight(string x, int y, int z, string t, int n1, int n2);
	string isOffHorse();
	string isExhausted();
	string displayName();
	bool onHorse2();
	bool NotTired();
	int Stam();
	string displayWep();
	int StamCost();
	int ShowChance();
  private:
	Weapon wep;
	string name;
    bool onHorse;
    int stamina; 
	string holding;
};

#endif
