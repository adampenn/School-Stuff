// Name: Joeann Eastland
// Source File: "Knight"

//// Files & Libraries: ///////////

#include "Knight.h"
#include <iostream>
using namespace std;

//// Knight class definition //////////

string Knight::get_name()
{
  return name;
}

  Knight::Knight
  (string n, int s, string t, int sr, int hc)
: name(n), stamina(s), weapon_in_hand(t,sr,hc), on_Horse(true)
{
}

bool Knight::attack()
{
  if (stamina > 0)
  {
    stamina = stamina - weapon_in_hand.get_stamina();

    if (weapon_in_hand.hit())

      return true;

    else
      return false;
  }
  return false;
}

void Knight::unhorse()
{
  on_Horse = false;
}

bool Knight::exhausted()
{
  if (stamina >= 0)
  {
    return false;
  }
  else 
    return true;
}

bool Knight::onhorse()
{
  if (on_Horse)
  {
    return true;
  }
  else 
    return false;
}

void Knight::display()
{
  cout << name << " now is";
  if (on_Horse)
  {
    cout << " on the horse, ";
  }
  else 
    cout << " off the horse, ";
  if (exhausted())
  {
    cout << " and " << name << " is exhausted \n";
  }
  else 
    cout << " with " << stamina << " point of stamina. \n";

  cout << name << " is holding a/an ";
  weapon_in_hand.display();
}


