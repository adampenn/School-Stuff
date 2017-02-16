//Name: Yousef Gerfal
//Project# 4
#include<iostream>
#include<iomanip>
#include "Weapon.h"
#include "Knight.h"
#include "Random.h"
using namespace std;

void Weapon::set(string n, int s, int h)
{
  name=n;
  stamina_Required=s;
  hit_Chance=h;
}

void Weapon::display()
{
  cout << name << ", needs " << stamina_Required << " stamina, and the hit chance is " << hit_Chance << "." << endl;
}

int Weapon::get_stamina()
{
  return stamina_Required;
}

bool Weapon::hit()
{
  Random chance(1, hit_Chance);
  if (chance.get() == hit_Chance)
    return true;
  else
    return false;
}


