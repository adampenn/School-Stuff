#include<iostream>
#include"knight.h"
#include"weapon.h"
#include<string>
using namespace std;
knight::knight(string l, int s, string f, int a, int b)
  :name(l), stamina(s), weapon_in_hand(f,a,b), on_horse(true)
{}
void knight::unhorse_yourself()
{
  on_horse=false;
}
bool knight::are_you_on_horse()
{
  if(on_horse==true)
    return (true);
  else
    return (false);
}
bool knight::charge()
{
  int stam=weapon_in_hand.get_stamina();
  stamina=stamina-stam;
  bool hit=weapon_in_hand.did_i_hit();
  return (hit);
}
bool knight::exhausted()
{
  if (stamina>0)
    return (false);
  else
    return (true);
}

void knight::display()
{
    cout << name << " has " << stamina << " stamina left, and is still on their horse." << endl;
}
