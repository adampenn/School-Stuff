//Joust by Hortense Rush
#include"Random.h"
#include"weapon.h"
#include<iostream>
#include<string>
using namespace std;

/////////////////////////////////////////////Weapon

Weapon::Weapon(string x, int y, int z)
	: type(x), staminaCost(y), hitchance(z)
{
}

bool Weapon::didHit(int m){
	Random r(1,100);
	int rn=r.get();
	if (rn>m){
		return false;
	}else{
		return true;
	}
}

int Weapon::StamCost(){
	return this->staminaCost;
}
int Weapon::ShowChance(){
	return this->hitchance;
}
string Weapon::displayWep(){
	return this->type;
}
