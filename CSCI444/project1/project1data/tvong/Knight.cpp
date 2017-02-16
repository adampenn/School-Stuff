#include <iostream> 
#include"Knight.h"
#include"Weapon.h" 
#include<string>
#include<cstdlib> 
using namespace std; 

bool Knight::attack()
{
  if(stamina>0)
  {
    stamina=stamina- weapon_in_hand.get_stamina(); 
    if(weapon_in_hand.hit())
      return true; 
    else 
      return false;
   }else 
     return false; 
} 

void Knight::unhorse()
{
  on_horse = false; 
} 

bool Knight::exhausted()
{ 
  if(stamina>0) 
    return false; 
  else
    return true; 
} 

bool Knight::onhorse() 
{ 
  if(on_horse) 
    return true; 
  else
    return false; 
} 

void Knight::display()
{ 
  cout<<name<<" is currently "; 
 
  if(on_horse) 
    cout<<"on the horse, "; 
 
  else 
    cout<<"off the horse, "; 
 
  if(exhausted())
    cout<<"and is exhausted.\n"<<endl; 
  
  else
    cout<<"with "<< stamina<<" points of stamina.\n";
    cout<<name<<" is holding a "; 
    weapon_in_hand.display(); 
} 
 

