//Randell Gallardo  
#include "weapon.h"
#include "Random.h"
#include<iostream>
using namespace std;

void Weapon::set(string n, int st_r, int hit_c) //setting weapon parameters
{
  name=n;
  stamina_required=st_r;
  hit_chance=hit_c;

}
int Weapon::get_stamina() //getting stamina for weapon
{
  return stamina_required;
}
bool Weapon::hit() //see if weapon hits the opponent 
{
  Random chance(1, hit_chance);
  if(chance.get() == hit_chance)
    return true;
  else
    return false;
}
void Weapon::display() //displays the weapon
{
  cout << name << " which needs " << stamina_required << " stamina, and a hit chance of " << hit_chance << endl;
}


