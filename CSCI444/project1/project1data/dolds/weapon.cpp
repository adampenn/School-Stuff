#include "weapon.h"
#include "Random.h"
#include<iostream>
using namespace std;

//CLASS DEFINITION

Weapon::Weapon(int hit, int stamina) //constructor
  : hit_chance(hit), stamina_cost(stamina)//initialization
{
}

int Weapon::get()
{
  return stamina_cost;
}

bool Weapon::did_i_hit()
{
  Random r(1,100);
  int random_number=r.get();
  if(random_number<hit_chance)
  {
    return true;
  }
  else
  {
   return false;
  }
}

