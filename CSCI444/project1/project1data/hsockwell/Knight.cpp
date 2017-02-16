// Hiroko Sockwell, Knight.cpp
#include<iostream>
#include<string>
#include "Knight.h"
#include "Weapon.h"
using namespace std;

//Knight class definition
Knight::Knight(bool o, int s, string n, int c, int h, string w) : onHorse(o), stamina(s), name(n), heldWeapon(c, h, w) 
{
}

void Knight::display()
{
  cout << name << " is ";
  if (stamina > 0)
    cout << "not exhausted (stamina = " << stamina << ") and is ";
  else
    cout << "exhausted (stamina = " << stamina << ") and is ";
  if (onHorse == true)
    cout << "still on their horse." << endl;
  else
    cout << "not on their horse." << endl;
  cout << name << " is using: ";
  heldWeapon.display();
}

void Knight::won(bool opponent)
{
  if (opponent == true)
    cout << name << "'s opponent is exhausted and cannot continue. " << name << " wins!" << endl;
  else
    cout << name << "'s opponent has been unhorsed. " << name << " wins!" << endl;
}

void Knight::unhorsed(bool hit)
{
  if (hit == true)
    onHorse = false;
}

bool Knight::lost()
{
  if (stamina < 1)
    return true;
  else if (onHorse == false)
    return true;
  else
    return false;
}

bool Knight::horse()
{
  return onHorse;
}

bool Knight::tired()
{
  if (stamina < 1)
    return true;
  else
    return false;
}

bool Knight::charge(int randomNumber)
{
  stamina -= heldWeapon.cost(); 
  if (heldWeapon.chance() >= randomNumber)
    return true;
  else
    return false;
}
