#ifndef WEAPON_H
#define WEAPON_H
#include<iostream>
#include<string>
#include"Random.h"
using namespace std;


//class declaration for weapon
class Weapon
{
  private:
  int stamina_Required, hit_Chance;
  string name;
  
  public:
  void set(string, int, int);
  void display();
  int get_stamina();
  int get_hit_Chance();
  string get_name();
  bool hit();
};

#endif
