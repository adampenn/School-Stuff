//Randell Gallardo
#include "knight.h"
#include "weapon.h"
#include <iostream>
using namespace std;

bool knight::attack() //simulates an attack
{
  if(stamina > 0)
  {
    stamina = stamina - weapon_in_hand.get_stamina();
    if(weapon_in_hand.hit())
      return true;
    else
      return false;
  }else 
  {
    cout << "something broke, attack failed" << endl;    //in case something goes wrong
    return false;
  }
}
bool knight::exhausted() //sees if the knight is exhausted 
{
  if(stamina > 0)
    return false;
  else
    true;
}
bool knight::onhorse() //tells if the knight is still on the horse
{
  if(mounted)
    return true;
  else
    return false;
}

void knight::display() //displays knights status
{
  cout << name << " is currently";
  if(mounted)
    cout << " mounted on the horse";
  else 
    cout << " kicked off horse";
  if( exhausted() )
    cout <<" and exhausted  ";
  else if( mounted ) //mounted and not exhausted
    cout <<" with " << stamina << " left of stamina. ";
  cout << endl;

  cout  << name << " is grasping a ";
  weapon_in_hand.display();
}
void knight::kicked_off() //tells you if you get kicked off
{
  mounted = false;
}


void knight::set(string n, int stam,string weapon_n, int stam_req, int hit_cha) //sets knights parameters
{
  name = n;
  stamina = stam;
  Weapon temp_weapon;
  temp_weapon.set( weapon_n, stam_req, hit_cha);
  weapon_in_hand = temp_weapon;
}
