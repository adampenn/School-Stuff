#include<iostream>
#include"weap.h"
#include"knig.h"
#include"Random.h"
using namespace std;

Weapon::Weapon(string w, int c, int hc)
  : weapon_type(w), stamina_cost(c), hit_chance(hc)
{
}

bool Weapon::did_you_hit(void)
{
//the rock says know...
  int your_role;
  Random generatoure(1,100);
  your_role=generatoure.get();
  if(your_role <= hit_chance)
    return true;
  else 
    return false;
}

int Weapon::get_stamina_cost(void)
{
  int cost;
  cost=stamina_cost;
  return cost;
}

void Weapon::display(void)
{
  cout <<"This knight is wielding " << weapon_type <<" that requires " << stamina_cost <<" stamina, and has a " << hit_chance <<"% chance to hit." <<endl;
}
