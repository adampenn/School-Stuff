#include<iostream>
#include"knight.h"
#include"weapon.h"
using namespace std;

knight::knight(string na, int sta_k, string we, int st, int hc)
  : name(na), stamina(sta_k), weapon_inhand(we,st,hc), on_horse(true)
{
}

bool knight::attack()
{
  int x=weapon_inhand.get_stamina();
  stamina= stamina-x;

  bool hit =weapon_inhand.did_you_hit();
  return(hit);
 
}


bool knight::horse_status()
{
 on_horse=false; 
}
bool knight::are_you_on_horse()
{
  if (on_horse== true)
  {
    return true;
  }
  else return false;
}

bool knight::exhausted()
{
 if (stamina>0)
 {
   return false;
 }else 
   return true;
  
} 

void knight::display()

{
 if (stamina>0 && on_horse==true)
  {  cout<<name<<" is not exhausted (stamina= "<<stamina<<") and is still on the horse."<<endl;
  }
    else if (stamina<0 && on_horse==true)
    {
      cout<<name<<" is exhausted and is still on the horse."<<endl;
    }
    else if (stamina>0 && on_horse==false)
  {
    cout<<name<<" is off the horse."<<endl;
  }
    else
 {
   cout<<name<<" is exhausted and off the horse.";
 }
}

