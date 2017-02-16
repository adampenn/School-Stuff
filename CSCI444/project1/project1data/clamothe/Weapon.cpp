#include"Weapon.h"
#include"Random.h"
#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;

Weapon::Weapon(int n, int s, int h): name(n),stam(s), hit(h)
{
}
string Weapon::getName()
{
  return(name);
}
int Weapon::getStam()
{
  return(stam);
}
int Weapon::getHit()
{
  return(hit);
}
bool Weapon::hit_check()
{
  Random r(1,100);
  int rn=r.get();

  if (rn<=hit)
    return(true);
  else
    return(false);
}
