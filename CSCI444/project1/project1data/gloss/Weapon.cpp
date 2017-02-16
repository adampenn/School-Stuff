#include "Weapon.h"
#include "Random.h"
#include<iostream>
#include<iomanip>
#include <cstdlib>
#include <cstddef>
#include <ctime>
using namespace std;
Weapon::Weapon(string n, int a, int b){

	name=n;
	hit_chance=a;
	stamina_required=b;
}

int Weapon::get_stamina_required(void)
{
	return stamina_required;
}

bool Weapon::did_you_hit(void)
{
	Random r(1,100);
	int rn=r.get();

	if(rn<=hit_chance)
		return true;
	else
		return false;
}

void Weapon::wdisplay1(){
	cout<<"  Weapon: "<<name<<endl;
	cout<<"    Hit chance: "<<hit_chance<<endl;
	cout<<"    Stamina required: "<<stamina_required<<endl;
}

void Weapon::wdisplay2()
{
	cout<<name;
}
