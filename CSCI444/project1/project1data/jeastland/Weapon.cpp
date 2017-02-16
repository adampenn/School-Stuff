//Joeann Eastland
//Source file "Weapon"
//

//////FIles & Library://///////////////

#include "Weapon.h"
#include "Random.h"
#include<iostream>

using namespace std;

//////////defing functions stored in Weapon class///////////

Weapon::Weapon(string n, int s, int h)
{
  name=n;
  stamina_Required=s;
  hit_Chance=h;

}


void Weapon::display()
{
  cout << name << ", which needs " << stamina_Required << " stamina, and has a " << hit_Chance << " % chance to hit" << endl;

}

int Weapon::get_stamina()
{
  return stamina_Required;
}

bool  Weapon::hit() //Did you hit?
{
  Random chance(0, 1000);
  int Random = chance.get();
  if (Random <= hit_Chance)
  {
    return true;
  }
  else
    return false;
}
