#include"Weapon.h"
#include"Random.h"
#include<iostream>
#include<string>

using namespace std;

Weapon::Weapon(int s, int h)
  : stam(s), hit(h)
{
}
int Weapon::getStam()
{
  return(stam);
}
int Weapon::getHit()
{
  return(hit);
}
bool Weapon::weaponchance()
{
  Random r(1,100);
  int random=r.get();

  if (random<=hit)
    return(true);
  else
    return(false);
}
