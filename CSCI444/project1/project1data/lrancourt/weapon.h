#ifndef __WEAPON_H__
#define __WEAPON_H__

#include<string>

#include"Random.h"

using namespace std;

class weapon
{
public:
	weapon(int hitChance, int stamUse, string name)
		: _hitChance(hitChance), _stamUse(stamUse), _name(name) {}

	//getters
	bool getHit();
	int getHitChance() { return _hitChance; }
	int getStamUse() { return _stamUse; }
	string getName() { return _name; }	
protected:
	int _hitChance;
	int _stamUse;
	string _name;
};

#endif
