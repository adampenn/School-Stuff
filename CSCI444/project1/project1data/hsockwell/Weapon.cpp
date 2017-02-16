// Hiroko Sockwell, Weapon.cpp
#include<iostream>
#include<string>
#include "Weapon.h"
using namespace std;

//Weapon class definition
Weapon::Weapon(int s, int c, string n) : staminaCost(s), hitChance(c), name(n)  
{
}

void Weapon::display()
{
  cout << name << " that requires " << staminaCost << " stamina and has a " << hitChance << "\% chance to hit." << endl << endl;
}

int Weapon::cost()
{
  return staminaCost;
}

int Weapon::chance()
{
  return hitChance;
}
