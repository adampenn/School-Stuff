#include "Weapon.h"
#include "Random.h"
#include<iostream>
#include<string> 
#include<cstdlib>
using namespace std; 

void Weapon::set(string n, int s, int h)
{ 
  name=n; 
  stamina_required=s; 
  hit_chance=h; 
}

void Weapon::display()
{
  cout<<name<<", which needs "<<stamina_required<< " stamina, and has a hit chance of " <<hit_chance<<endl;  
}

int Weapon::get_stamina()
{ 
  return stamina_required; 
}


bool Weapon::hit(void)
{
 Random r(1,100); 
 int rn;  
 rn=r.get(); 
 if(rn<=hit_chance)
 return true; 
 else
 return false;
}
