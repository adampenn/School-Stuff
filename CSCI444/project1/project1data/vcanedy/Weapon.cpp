#include "Weapon.h"
#include "Knight.h"
#include "Random.h"
#include <iostream>
#include <string>
using namespace std;

Weapon::Weapon(string t, int sr, int hc) : type(t), stamina_required(sr), hit_chance(hc)
{
}

int Weapon::get_stamina_required()
{
  return stamina_required;
}

bool Weapon::did_you_hit()
{ 
  Random num_gen (1,100);
  int num = num_gen.get();
  if(num<=hit_chance)
    return true;
  else
    return false;
}

void Weapon::display()
{
  cout << type << " that requires " << stamina_required << " stamina and has a " << hit_chance << " percent chance to hit" << endl;
}


   

