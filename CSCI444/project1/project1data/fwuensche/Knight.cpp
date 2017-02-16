#include<iostream>
#include"Knight.h"
#include<string>
using namespace std;

  Knight::Knight(string n, int s, string wn, int ws, int wh)
:stamina(s), name(n), w(wn, ws, wh)
{
}
void Knight::getstamina()
{
 stamina = w.checkstamina(stamina);
}
void Knight::printname()
{
  cout << name;
}
bool Knight::checkstam()
{
  if(stamina <= 0)
  {
    return true;
  }
  else if(stamina > 0)
  {
    return false;
  }
}
bool Knight::checkmount(bool h)
{
  if ( h == true)
  {
    return false;
  }
  else
  {
    return true;
  }
}
void Knight::display(bool mount)
{
  if(checkstam() == true && mount == false)
  {
    cout << name << " is exauhsted (stamina = " << stamina << ") and has been knocked off of the horse." << endl;
  }
  else if(checkstam() == true && mount == true)
  {
    cout << name << " is exauhsted (stamina = " << stamina << ") and is still on the horse." << endl;
  }
  else if(checkstam() == false && mount == false)
  {
    cout << name << " is not exauhsted (stamina = " << stamina << ") and has been knocked off of the horse." << endl;
  }
  else if(checkstam() == false && mount  == true)
  {
    cout << name << " is not exauhsted (stamina = " << stamina << ") and is still on the horse." << endl;
  }
  cout << name << " is using: "; 
  w.displayname();
  cout << " that requires ";
  w.displaystamreq();
  cout << " satmina and has a ";
  w.displayhitchance();
  cout << "% chance to hit."<< endl;
}
bool Knight::didithit()
{
  w.joust();
  hit = w.checkhit();
  if( hit == true)
  {
    return true;
  }
  else
  {
    return false;
  }
}
