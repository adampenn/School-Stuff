//Joust by Hortense Rush
#ifndef WEAPON_H
#define WEAPON_H

#include<string>
using namespace std;

class Weapon {
  public:
    bool didHit(int x); //constructor
	Weapon(string x, int y, int z);
	int StamCost();
	int ShowChance();
	string displayWep();
  private:
    string type;
    int hitchance;
    int staminaCost;
};

#endif
