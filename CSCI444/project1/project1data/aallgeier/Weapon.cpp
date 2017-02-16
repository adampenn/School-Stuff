#include<iostream>
#include<string>
#include"Weapon.h"
#include"Knight.h"
using namespace std;

//weapon class definition
Weapon::Weapon(string wp, int hc, int sr)
  :weapon(wp), hit_chance(hc), stamina_required(sr)
  {
  }
  
int Weapon::get_hit_chance()
{
return hit_chance;
}

int Weapon::get_stamina_required(void)
{
return stamina_required;
}

string Weapon::getknight()
{
  return weapon;
}



