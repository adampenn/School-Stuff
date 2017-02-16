// File:  Weapon.cpp
// Author: Rod Center
// class definition

#include <string>
#include <iostream>
#include "Weapon.h"
#include "Random.h"

using namespace std; 



  Weapon::Weapon(string _Type, int _StaminaCost, int _HitPercent)
    :_Type(_Type), _StaminaCost(_StaminaCost), _HitPercent(_HitPercent)
    {}

int Weapon::GetCost()
{
  return _StaminaCost;
}

int Weapon::SetCost(int Staminacost)
{
  _StaminaCost=_StaminaCost;
}

bool Weapon::GetHit()
{
  Random theGenerator(1,100);
  int rn;
  rn=theGenerator.get();
  if(rn<=_HitPercent)
    return true;
  else
    return false;
}

void Weapon::display()
{

//Weapon Statistics
    cout << "Weapon Type: "<<_Type<<endl;
    cout << "Stamina Cost: "<<_StaminaCost<<endl;
    cout << "Hit Chance: "<<_HitPercent<<"/100\n";
}
