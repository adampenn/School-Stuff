//Ginette Mckamey CSCI 111

#include<iostream>
#include<string>
#include<iomanip>
#include"Knight.h"
#include"Random.h"
using namespace std; 

  Knight::Knight(string n, int s, string type, int sr, int hc)
:name(n), stamina(s), onhorse(true), weapon_in_hand(Weapon(type,sr,hc))
{
}
//On horse function
bool Knight::are_you_on_horse(void)
{

  if(onhorse)
    return true;
  else 
    return false;
}

void Knight::unhorse_yourself(void)
{
  onhorse = false;
}

//Exhausted function
bool Knight::are_you_exhausted(void)
{
  if(stamina > 0)
    return false;
  else
    return true;
}
//Charge function
bool Knight::charge(void)
{
  if (onhorse == true)
  {
    int x = weapon_in_hand.get_stamina_required(); 
    weapon_in_hand.get_stamina_required();
    weapon_in_hand.did_you_hit(); 
  }
}
//display function
void Knight::display()
{
  cout << name << " is ";
  if (are_you_exhausted()== false)
    cout << "not exhausted ";
  else
    cout << "exhausted";
  cout << " (stamina = ";
  cout << stamina << ") and"; 

  if(are_you_on_horse() == true)
    cout << " is still on the horse." << endl;
  else
    cout << " has been knocked of the horse." << endl;


}
