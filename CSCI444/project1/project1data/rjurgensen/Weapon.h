#include<iostream>
#include<iomanip>
using namespace std;

#ifndef WEAPON_H
#define WEAPON_H

class Weapon
{
  private:
    int stamina_Required, hit_Chance;
    string name;

  public:
    void set(string, int, int);
    void display();
    int get_stamina();
    bool hit();
};
#endif

