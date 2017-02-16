#include"weapon.h"
#include<iostream>
#include<string>
using namespace std;


//class definition

void Weapon::set(string n, int s, int h)
{
  name=n;
  stamina_Required=s;
  hit_Chance=h;
}


void Weapon::display()
{
  cout<<name<<", which needs "<<stamina_Required<<" stamina, and has a hit chance of "
      <<hit_Chance<<endl;
}

//get_stamina() , get_hit_chance() and get_name() are methods which just return
//the value of whichever attribute the method name specifies it is suppose to return
int Weapon::get_stamina()
{
  return stamina_Required;
}

int Weapon::get_hit_Chance(){
	return hit_Chance;
}

string Weapon::get_name(){
	return name;
}

bool Weapon::hit() //did you hit?
{
  Random chance(1, hit_Chance);

  if (chance.get() == hit_Chance)
    return true;
  else
    return false;
}
