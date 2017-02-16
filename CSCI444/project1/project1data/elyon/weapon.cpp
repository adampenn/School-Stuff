#include<string>
#include<iostream>
#include"weapon.h"
#include"Random.h"
using namespace std;
bool weapon::did_i_hit()
{
  Random r(1,100);
  int rn=r.get();
  if (rn<hit_chance)
    return (true);
  else
    return (false);
}
int weapon::get_stamina()
{
  return (stamina_required);
}
weapon::weapon(string n, int a, int b)
  :type(n), stamina_required(a), hit_chance(b)
{}
void weapon::display()
{
  cout << type << " requires " << stamina_required << " stamina for a " << hit_chance << " chance to hit" << endl;
}
