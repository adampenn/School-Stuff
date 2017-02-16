#include<iostream>
#include<string>
#include"Weapon.h"
#include"Random.h"
using namespace std;

Weapon::Weapon(string wn, int ws, int wh)
  :name(wn), stamreq(ws), hitchance(wh)
{
}
int Weapon::checkstamina(int s)
{
 s = s - stamreq;
  return s;
}
void Weapon::displayhitchance()
{
  cout << hitchance;
}
void Weapon:: displayname()
{
  cout << name;
}
void Weapon::displaystamreq()
{
  cout << stamreq;
}
bool Weapon::checkhit()
{
  if(randnum <= hitchance)
  {
    return true;
  }
  else if(randnum > hitchance)
  {
    return false;
  }
}
int Weapon::joust()
{
  Random r(1,100);
  randnum = r.get();
  return randnum;
}
