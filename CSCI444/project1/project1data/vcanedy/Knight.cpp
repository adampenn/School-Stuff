#include "Weapon.h"
#include "Knight.h"
#include "Random.h"
#include <iostream>
#include <string>
using namespace std;

Knight::Knight(string n, int s) : name(n), stamina(s)
{
}

bool Knight::on_horse()
{
  if (stamina > 0)
    return true;
  else 
    return false;
}

bool Knight::are_you_exhausted()
{
  if (stamina<=0)
    return true;
  else 
    return false;
}

void Knight::charge()
{
  if (stamina > 0)
  {
    stamina = stamina - stamina_required;
  }
}

void Knight::unhorse()
{
  on_horse = false;
}

void Knight::display()
{
  cout << name << " is ";
  if (exhausted())
    cout << "exhausted ";
  else
    cout << "not exhausted (stamina = " << stamina << ") ";
  if (on horse())
    cout << "and is still on the horse." << endl;
  else
    cout << "and has been knocked off the horse." << endl;
  cout << name << " is holding a ";
  weapon_in_and.display();
}
}
