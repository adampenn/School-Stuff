#include"Weapon.h"
#include"Random.h"
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

Weapon::Weapon(string t, int h, int s)
  : type(t), hit_chance(h), stamina_required(s)
{
}
  void Weapon::display()
{
}
  void Weapon::hit_chance()
{
  Random theGenerator(1,100);
  
  int hc;

  hc = theGenerator.get();

}
  bool Weapon::did_you_hit()
{
  Random theGenerator(1,100);

  int rn;
  int hc;

 rn = theGenerator.get();
 if(rn <= hc)
   return true;
 else
   return false;
}

 int Weapon::stamina_required()
{
 int stam_cost(6);
  
  int sr;

  sr = stam_cost;
}

 string Weapon::type()
{
  string type1("Sword");
}
