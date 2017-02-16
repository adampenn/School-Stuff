#include"Knight.h"
#include"Weapon.h"
#include<iostream>

using namespace std;

Knight::Knight(string n, int s, string t, int sr, int h)
  : horse(true), name(n), stam(s), weapon(sr, h), type(t)
{
}
void Knight::dehorse()
{
  horse = false;
}
bool Knight::stamina()
{
  if (stam<=0)
    return true;
  else
    return false;
}
bool Knight::mounted()
{
  if (horse)
    return true;
  else
    return false;
}
void Knight::display()
{
  int stamcost;
  int chance;
  stamcost = weapon.getStam();
  chance = weapon.getHit();
  if (stam<=0)
    cout << name << " is exhausted(stamina=" << stam;
  else
    cout << name << " is not exhausted(stamina=" << stam;
  if (horse)
  {
    cout << ") and is still on the horse" << endl;
    cout << name << " is using: " << type << " that requres " << stamcost << " stamina and has a " << chance << "% chance to hit" << endl;
  }
  else
  {
    cout << ") and has been knocked off the horse" << endl;
    cout << name << " is using: " << type << " that requres " << stamcost << " stamina and has a " << chance << "% chance to hit" << endl;
  }
}
bool Knight::charge()
{
  int stamcost;
  stamcost=weapon.getStam();
  stam-=stamcost;
  bool chance;
  chance=weapon.weaponchance();
  
  return chance;
}
