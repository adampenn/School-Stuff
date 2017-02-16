//Jackson Coit// CSCI 111 
#include "Knight.h"
#include "Weapon.h"
#include<iostream>
using namespace std;

bool knight::attack()
{
  if(stamina > 0)
  {
    stamina = stamina - weapon_in_hand.get_stamina();
    if(weapon_in_hand.hit())
      return true;
    else
      return false;
  }
  }

  bool knight::exhausted()
  {
    if (stamina > 0)
      return false;
    else
      return true;
  }

  bool knight::onhorse()
  {
    if(on_Horse)
      return true;
    else
      return false;
  }

  void knight::unhorse()
  {
    on_Horse = false;
  }


  void knight::display()
  {
    cout << name << " is currently ";
    if(on_Horse)
      cout << " on the horse ";
    else 
      cout << " unhorsed";
    if(exhausted())
      cout << " exhausted";
    else if(on_Horse)
      cout << " with " << stamina << " points of stamina. ";
    cout << endl;
    cout << name << " is holding a ";
    weapon_in_hand.display();
  }

  void knight::set(string n, int s, string t, int sr, int hc)
  {
    name=n;
    stamina=s;
    Weapon wep_sub;
    wep_sub.set(t, sr, hc);
    weapon_in_hand = wep_sub;
  }




