#include<iostream>
#include<string>
#include"Random.h"
#include"knight.h"
using namespace std;


bool Knight::attack()
{
  if(stamina > 0)
  {
    stamina=stamina-weapon_in_hand.getStamina();
    if(weapon_in_hand.hit())
      return true;
    else 
      return false;
  }
  else 
    return false;
}


void Knight::unhorse()
{
  onHorse = false; 
}


bool Knight::exhausted()
{
  if (stamina>0)
    return false;
  else
    return true;
}


bool Knight::onhorse()
{
  if(onHorse)
    return true;
  else
    return false;
}


void Knight::display()
{
  cout << name << " is currently ";
  if(onHorse)
    cout << "on the horse, ";
  else
    cout << "off the horse, ";
      if(exhausted())
        cout << "and is exhausted";
      else
        cout << "with a stamina of " << stamina << endl;
  cout << name << " is wielding a ";
  weapon_in_hand.display();
}

