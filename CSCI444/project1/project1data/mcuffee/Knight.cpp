#include"Weapon.h"
#include"Random.h"
#include"Knight.h"
#include<iostream>
#include<string>
using namespace std;

Knight::Knight(string n, int st)
  : name(n), stamina(st)

{ 
  name = n;
  stamina = st;
}
  void Knight::display
{
  cout << name << endl;
  cout << stamina << endl;
}

  void Knight::name()
{
  string name1();

}

  int Knight::stamina()
{
  int st;
  cout << "Enter your stamina: " << st << endl;
}

  bool Knight::on_horse()
{
  bool oh;
  int st;

 if(st > 0)
   return true;
 else
   return false;
}

  bool Knight::exhausted()
{
  bool ex;
  int st;

  if(st >0)
    return false;
  else
    return true;
}
