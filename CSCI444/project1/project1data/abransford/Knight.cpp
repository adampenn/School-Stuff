// Knight CPP File

// Includes
#include<iostream>
#include"Random.h"
#include "Knight.h"
#include<string>
using namespace std;

 // When the knight attacks , this calculated the left stamina
 // Calculates if Weapon hit by calling weaponhit function in weapon.cpp
  bool Knight::attack()
 {
  if(staminaknight > 0)
  {
    staminaknight=staminaknight-knightsweapon.show_stamina();
    if(knightsweapon.weaponhit())
      return 1;
    else
      return 0;
  }else
    return 0;

}
// If knight is knocked it will set variable to 0 
  void Knight::isKnocked()
{
  isOnhorse = 0;

}
// if stamina is over , it will return true
  bool Knight::knightIsExausted()
{
 if (staminaknight>0)
    return 0;
  else
    return 1;

}
// If the Knight is still on horse , this function will return true
  bool Knight::onhorse()
{
 if(isOnhorse)
    return 1;
  else
    return 0;

}
// this will display the stats of the knights
 void Knight::showstats()
{

 cout<<knightname;
 
  if(knightIsExausted())
    cout<<" is exhausted ";
  else
    cout<<" is not exausted (stamina = " << staminaknight <<" ) ";

  if (isOnhorse)
    cout<<"and is still on the horse " << endl ;
  else
    cout<<"and has been knocked off the horse " << endl;
  
  cout<<knightname<<" is using: ";
  knightsweapon.showstats();

}
// This Will Set the stats of the Knights after the main gets the information
 void Knight::setstats(string knightsname, int knightstamina, string weaponname, int weaponstamina, int weaponchance)
  {
    knightname=knightsname;
    staminaknight = knightstamina;
    knightsweapon.setstats(weaponname,weaponstamina,weaponchance);
    isOnhorse=1;
  }




