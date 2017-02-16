//Ginette Mckamey CSCI 111

#include<iostream>
#include<string>
#include<iomanip>
#include"Random.h"
#include"Weapon.h"
using namespace std; 

//Weapon class Definition

Weapon::Weapon(string type, int sr, int hc)
:weapon_type(type), stamina_required(sr), hit_chance(hc)
{
  type = weapon_type;
  stamina_required =sr; 
  hit_chance = hc;
}

bool Weapon::did_you_hit(void)
{

Random r(1,100);
int rn;
rn = r.get();
if (rn <= hit_chance)
return true;
else 
return false;

}
int Weapon::get_stamina_required(void)
{
  return stamina_required;
 
}
void Weapon::display()
{
  cout << "Weapon: " << weapon_type << endl;
  cout << "Hit chance: " << hit_chance << endl; 
  cout << "Stamina required: " << stamina_required << endl; 
cout << weapon_type << " needs " << stamina_required << " stamina, and has a hit chance of " << hit_chance;

}

