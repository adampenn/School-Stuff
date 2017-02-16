#include "knight.h"
#include "weapon.h"
#include<iostream>
using namespace std;

//CLASS DEFINITION
  Knight::Knight(string name,string weapon,int stam,int hit, int stamina)//constructor
: name(name), is_mounted(true),  stamina(stam), joust_weapon(Weapon(hit,stamina))
{
}

bool Knight::are_you_mounted()
{
  if (is_mounted==true)
  {
    return true;
  }
  else 
  {
   return false;
  }
}

bool Knight::are_you_exhausted()
{
  if (stamina<=0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void Knight::charge()
{
  stamina= stamina-joust_weapon.get();
  if(joust_weapon.did_i_hit()==true)
  {
is_mounted=false;
  }
  else
  {
    is_mounted=true;
  }
}

void Knight::display()
{
  if(stamina>0)
  {
    cout<<name<<" is unexhausted with "<<stamina<<" left."<<endl;
  }
  else
  {
    cout<<name<<" has been exhausted from combat."<<endl;
  }
if(is_mounted==true)
{
  cout<<" Despite the furiouse combat they have maintained their steed."<<endl;
}
else
{
  cout<<" Combat has knocked them from their steed."<<endl;
}
cout<<"\n\n"<<endl;
}

