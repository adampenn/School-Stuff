//Jackson Coit
#include"Weapon.h"
#include"Random.h"
#include<iostream>
using namespace std;

void Weapon::set(string n, int s, int h)
{
  name=n;
  stamina_Required=s;
  hit_chance=h;
}

int Weapon::get_stamina()
{
  return stamina_Required;
}

bool Weapon::hit()
{
  Random chance(1, hit_chance);

  if (chance.get() == hit_chance)
    return true;
  else
    return false;
}
void Weapon::display()
{
  cout << name << " that requires " << stamina_Required << " stamina, and has a " << hit_chance << " percent chance to hit." << endl;
}

