#include<iostream>
#include"Random.h"
#include"weapon.h"
using namespace std;
  weapon::weapon(string we, int st, int hc)
     : stamina(st), hitchance(hc), weapon_type(we)
{
}

 bool weapon::did_you_hit()
{
  Random theGenerator(1,100);
 int theroll=theGenerator.get();
  if (theroll<=hitchance)
  {
    return true;
  }else 
    return false;
}

void weapon::display()
{
  cout<<weapon_type<< " has "<< hitchance << " percent chance to hit and cost "<< stamina<< " to use."<<endl;
}

int weapon::get_stamina()
{
 return (stamina);
}

