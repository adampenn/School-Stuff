// Donnetta Rhymer 
// weapon.cpp

#include<iostream>
#include"Random.h"
#include"weapon.h"
#include"knight.h"

void Weapon::set(string n, int s, int h)
{
  name=n;
  staminaRequired=s;
  hitChance=h;
}
  

void Weapon::display()
{
  cout << name << ", which needs " << staminaRequired << " stamina, has a hit chance of " << hitChance;
}


int Weapon::getStamina()
{
  return staminaRequired;
}


bool Weapon::hit()
{
  Random theGenerator(1,100);
  int rn;
  rn=theGenerator.get();
  if(rn<=hitChance)
    return true;
  else
    return false;
}

