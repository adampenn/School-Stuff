// Name: Yousef Gerfal
// Project# 4
#include<iostream>
#include<iomanip>
#include "Knight.h"
#include "Weapon.h"
#include "Random.h"
using namespace std;

bool Knight::attack()
{
  if(stamina > 0)
  {
    stamina=stamina - weapon_in_hand.get_stamina();
    if(weapon_in_hand.hit())
      return true;
    else
      return false;
  }else
    return false;
}

void Knight::unhorse()
{
  on_Horse = false;
}

bool Knight::exhausted()
{
  if (stamina > 0)
    return false;
  else 
    return true;
}

bool Knight::onhorse()
{
  if(on_Horse)
    return true;
  else
    return false;
}

void Knight::display()
{
  cout << name << " now is ";
  if (on_Horse)
    cout << "on the horse, ";
  else 
    cout << "off the horse, ";
  if (exhausted())
    cout << "and is exhausted" <<endl;
  else
    cout << "with " << stamina << " points of stamina" <<endl;
  cout << "Also, "<< name << " is holding a ";
  weapon_in_hand.display();
}


