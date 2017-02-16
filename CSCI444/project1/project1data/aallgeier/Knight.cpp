#include<iostream>
#include<string>
#include"Knight.h"
#include"Weapon.h"
#include"Random.h"
using namespace std;

//knight class definition
Knight::Knight(string knight, Weapon wp)
   :name(knight), weapon(wp)
{
onHorse = true;
stamina = 100;
}
bool Knight::attack()
{
  int fight;
  stamina -= weapon.get_stamina_required();
  Random r(1,100);
  fight = r.get();
   if( fight <= weapon.get_stamina_required())
    {
     return true;
    }
   else
   {
     return false;
   }
}

void Knight::onhorse()
{
   onHorse = false;
}

bool Knight::still_on_horse()
{
  return onHorse;
}

string Knight::getknight()
 {
   return name;
 }

int Knight::get_stamina_required()
 {
   return stamina;
 }

Weapon Knight::getweapon()
 {
   return weapon;
 }
